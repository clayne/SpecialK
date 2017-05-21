/**
 * This file is part of Special K.
 *
 * Special K is free software : you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by The Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * Special K is distributed in the hope that it will be useful,
 *
 * But WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Special K.
 *
 *   If not, see <http://www.gnu.org/licenses/>.
 *
**/

#define _CRT_SECURE_NO_WARNINGS
#define NOMINMAX

#include <SpecialK/d3d8_backend.h>
#include <SpecialK/dxgi_backend.h>
#include <SpecialK/render_backend.h>

#include <SpecialK/core.h>
#include <SpecialK/log.h>

#include <SpecialK/config.h>

#include <cstdio>
#include <cstdlib>
#include <string>

#include <atlbase.h>
#include <comdef.h>

#include <SpecialK/log.h>
#include <SpecialK/utility.h>
#include <SpecialK/command.h>
#include <SpecialK/hooks.h>
#include <SpecialK/window.h>
#include <SpecialK/steam_api.h>

#include <SpecialK/diagnostics/compatibility.h>

volatile LONG __d3d8_ready = FALSE;

unsigned int
__stdcall
HookD3D8 (LPVOID user);

void
WINAPI
WaitForInit_D3D8 (void)
{
  while (! InterlockedCompareExchange (&__d3d8_ready, FALSE, FALSE))
    Sleep (config.system.init_delay);
}

typedef IUnknown*
  (STDMETHODCALLTYPE *Direct3DCreate8PROC)(  UINT           SDKVersion);

Direct3DCreate8PROC      Direct3DCreate8_Import       = nullptr;

typedef void (WINAPI *finish_pfn)(void);

__declspec (noinline)
IUnknown*
STDMETHODCALLTYPE
Direct3DCreate8 (UINT SDKVersion)
{
  WaitForInit_D3D8 ();
  WaitForInit      ();

  dll_log.Log ( L"[   D3D8   ] [!] %s (%lu) - "
                L"%s",
                  L"Direct3DCreate8",
                    SDKVersion,
                      SK_SummarizeCaller ().c_str () );

  IUnknown* d3d8 = nullptr;

  if (Direct3DCreate8_Import) {
    d3d8 = Direct3DCreate8_Import (SDKVersion);
  }

  if (d3d8 != nullptr) {
    // ...
  }

  return d3d8;
}

void
WINAPI
SK_HookD3D8 (void)
{
  static volatile ULONG hooked = FALSE;

  if (InterlockedCompareExchange (&hooked, TRUE, FALSE)) {
    return;
  }

  HMODULE hBackend = 
    (SK_GetDLLRole () & DLL_ROLE::D3D8) ? backend_dll :
                                   GetModuleHandle (L"d3d8.dll");

  dll_log.Log (L"[   D3D8   ] Importing Direct3DCreate8.......");
  dll_log.Log (L"[   D3D8   ] ================================");

  if (! _wcsicmp (SK_GetModuleName (SK_GetDLL ()).c_str (), L"d3d8.dll")) {
    dll_log.Log (L"[   D3D8   ]   Direct3DCreate8:   %ph",
      (Direct3DCreate8_Import) =  \
        (Direct3DCreate8PROC)GetProcAddress (hBackend, "Direct3DCreate8"));
  }

  else
  {
    bool bProxy = GetModuleHandle (L"d3d8.dll") != hBackend;

    if ( MH_OK ==
           SK_CreateDLLHook2 ( L"d3d8.dll",
                                "Direct3DCreate8",
                                 Direct3DCreate8,
                      (LPVOID *)&Direct3DCreate8_Import )
       )
    {
      if (bProxy)
      {
        (Direct3DCreate8_Import) =  \
          (Direct3DCreate8PROC)GetProcAddress (hBackend, "Direct3DCreate8");
      }

      dll_log.Log (L"[   D3D8   ]   Direct3DCreate8:   %p  { Hooked }",
        (Direct3DCreate8_Import) );
    }

    MH_ApplyQueued ();
  }

  HookD3D8 (nullptr);
}

void
WINAPI
d3d8_init_callback (finish_pfn finish)
{
  if (! SK_IsHostAppSKIM ()) {
    SK_BootD3D8 ();

    while (! InterlockedCompareExchange (&__d3d8_ready, FALSE, FALSE))
      Sleep (100UL);
  }

  finish ();
}


bool
SK::D3D8::Startup (void)
{
  const bool ret = SK_StartupCore (L"d3d8", d3d8_init_callback);

  return ret;
}

bool
SK::D3D8::Shutdown (void)
{
  return SK_ShutdownCore (L"d3d8");
}


unsigned int
__stdcall
HookD3D8 (LPVOID user)
{
  UNREFERENCED_PARAMETER (user);

  if (! config.apis.d3d8.hook) {
    return 0;
  }

  const bool success = SUCCEEDED (
    CoInitializeEx (nullptr, COINIT_MULTITHREADED)
  );

  {
    InterlockedExchange (&__d3d8_ready, TRUE);

    if (! (SK_GetDLLRole () & DLL_ROLE::DXGI))
      SK::DXGI::StartBudgetThread_NoAdapter ();
  }

  if (success)
    CoUninitialize ();

  return 0;
}