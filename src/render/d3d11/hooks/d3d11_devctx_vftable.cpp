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

#define __SK_SUBSYSTEM__ L"  D3D 11  "

#include <SpecialK/render/d3d11/d3d11_core.h>
#include <SpecialK/render/d3d11/d3d11_tex_mgr.h>
#include <SpecialK/render/d3d11/utility/d3d11_texture.h>

extern memory_tracking_s* __mem_map_stats__ (void);
extern target_tracking_s* __tracked_rtv__   (void);
#define mem_map_stats  (* __mem_map_stats__ ())
#define tracked_rtv    (* __tracked_rtv__   ())

__declspec (noinline)
HRESULT
WINAPI
D3D11Dev_CreateTexture2D_Override (
  _In_            ID3D11Device           *This,
  _In_      const D3D11_TEXTURE2D_DESC   *pDesc,
  _In_opt_  const D3D11_SUBRESOURCE_DATA *pInitialData,
  _Out_opt_       ID3D11Texture2D        **ppTexture2D );

D3D11Dev_CreateRasterizerState_pfn                  D3D11Dev_CreateRasterizerState_Original                  = nullptr;
D3D11Dev_CreateSamplerState_pfn                     D3D11Dev_CreateSamplerState_Original                     = nullptr;
D3D11Dev_CreateBuffer_pfn                           D3D11Dev_CreateBuffer_Original                           = nullptr;
D3D11Dev_CreateTexture2D_pfn                        D3D11Dev_CreateTexture2D_Original                        = nullptr;
D3D11Dev_CreateRenderTargetView_pfn                 D3D11Dev_CreateRenderTargetView_Original                 = nullptr;
D3D11Dev_CreateShaderResourceView_pfn               D3D11Dev_CreateShaderResourceView_Original               = nullptr;
D3D11Dev_CreateDepthStencilView_pfn                 D3D11Dev_CreateDepthStencilView_Original                 = nullptr;
D3D11Dev_CreateUnorderedAccessView_pfn              D3D11Dev_CreateUnorderedAccessView_Original              = nullptr;

D3D11Dev_CreateVertexShader_pfn                     D3D11Dev_CreateVertexShader_Original                     = nullptr;
D3D11Dev_CreatePixelShader_pfn                      D3D11Dev_CreatePixelShader_Original                      = nullptr;
D3D11Dev_CreateGeometryShader_pfn                   D3D11Dev_CreateGeometryShader_Original                   = nullptr;
D3D11Dev_CreateGeometryShaderWithStreamOutput_pfn   D3D11Dev_CreateGeometryShaderWithStreamOutput_Original   = nullptr;
D3D11Dev_CreateHullShader_pfn                       D3D11Dev_CreateHullShader_Original                       = nullptr;
D3D11Dev_CreateDomainShader_pfn                     D3D11Dev_CreateDomainShader_Original                     = nullptr;
D3D11Dev_CreateComputeShader_pfn                    D3D11Dev_CreateComputeShader_Original                    = nullptr;

D3D11Dev_CreateDeferredContext_pfn                  D3D11Dev_CreateDeferredContext_Original                  = nullptr;
D3D11Dev_CreateDeferredContext1_pfn                 D3D11Dev_CreateDeferredContext1_Original                 = nullptr;
D3D11Dev_CreateDeferredContext2_pfn                 D3D11Dev_CreateDeferredContext2_Original                 = nullptr;
D3D11Dev_CreateDeferredContext3_pfn                 D3D11Dev_CreateDeferredContext3_Original                 = nullptr;
D3D11Dev_GetImmediateContext_pfn                    D3D11Dev_GetImmediateContext_Original                    = nullptr;
D3D11Dev_GetImmediateContext1_pfn                   D3D11Dev_GetImmediateContext1_Original                   = nullptr;
D3D11Dev_GetImmediateContext2_pfn                   D3D11Dev_GetImmediateContext2_Original                   = nullptr;
D3D11Dev_GetImmediateContext3_pfn                   D3D11Dev_GetImmediateContext3_Original                   = nullptr;

D3D11_RSSetScissorRects_pfn                         D3D11_RSSetScissorRects_Original                         = nullptr;
D3D11_RSSetViewports_pfn                            D3D11_RSSetViewports_Original                            = nullptr;
D3D11_VSSetConstantBuffers_pfn                      D3D11_VSSetConstantBuffers_Original                      = nullptr;
D3D11_VSSetShaderResources_pfn                      D3D11_VSSetShaderResources_Original                      = nullptr;
D3D11_PSSetShaderResources_pfn                      D3D11_PSSetShaderResources_Original                      = nullptr;
D3D11_PSSetConstantBuffers_pfn                      D3D11_PSSetConstantBuffers_Original                      = nullptr;
D3D11_GSSetShaderResources_pfn                      D3D11_GSSetShaderResources_Original                      = nullptr;
D3D11_HSSetShaderResources_pfn                      D3D11_HSSetShaderResources_Original                      = nullptr;
D3D11_DSSetShaderResources_pfn                      D3D11_DSSetShaderResources_Original                      = nullptr;
D3D11_CSSetShaderResources_pfn                      D3D11_CSSetShaderResources_Original                      = nullptr;
D3D11_CSSetUnorderedAccessViews_pfn                 D3D11_CSSetUnorderedAccessViews_Original                 = nullptr;
D3D11_UpdateSubresource_pfn                         D3D11_UpdateSubresource_Original                         = nullptr;
D3D11_DrawIndexed_pfn                               D3D11_DrawIndexed_Original                               = nullptr;
D3D11_Draw_pfn                                      D3D11_Draw_Original                                      = nullptr;
D3D11_DrawAuto_pfn                                  D3D11_DrawAuto_Original                                  = nullptr;
D3D11_DrawIndexedInstanced_pfn                      D3D11_DrawIndexedInstanced_Original                      = nullptr;
D3D11_DrawIndexedInstancedIndirect_pfn              D3D11_DrawIndexedInstancedIndirect_Original              = nullptr;
D3D11_DrawInstanced_pfn                             D3D11_DrawInstanced_Original                             = nullptr;
D3D11_DrawInstancedIndirect_pfn                     D3D11_DrawInstancedIndirect_Original                     = nullptr;
D3D11_Dispatch_pfn                                  D3D11_Dispatch_Original                                  = nullptr;
D3D11_DispatchIndirect_pfn                          D3D11_DispatchIndirect_Original                          = nullptr;
D3D11_Map_pfn                                       D3D11_Map_Original                                       = nullptr;
D3D11_Unmap_pfn                                     D3D11_Unmap_Original                                     = nullptr;

D3D11_OMSetRenderTargets_pfn                        D3D11_OMSetRenderTargets_Original                        = nullptr;
D3D11_OMSetRenderTargetsAndUnorderedAccessViews_pfn D3D11_OMSetRenderTargetsAndUnorderedAccessViews_Original = nullptr;
D3D11_OMGetRenderTargets_pfn                        D3D11_OMGetRenderTargets_Original                        = nullptr;
D3D11_OMGetRenderTargetsAndUnorderedAccessViews_pfn D3D11_OMGetRenderTargetsAndUnorderedAccessViews_Original = nullptr;
D3D11_ClearDepthStencilView_pfn                     D3D11_ClearDepthStencilView_Original                     = nullptr;

D3D11_PSSetSamplers_pfn                             D3D11_PSSetSamplers_Original                             = nullptr;

D3D11_VSSetShader_pfn                               D3D11_VSSetShader_Original                               = nullptr;
D3D11_PSSetShader_pfn                               D3D11_PSSetShader_Original                               = nullptr;
D3D11_GSSetShader_pfn                               D3D11_GSSetShader_Original                               = nullptr;
D3D11_HSSetShader_pfn                               D3D11_HSSetShader_Original                               = nullptr;
D3D11_DSSetShader_pfn                               D3D11_DSSetShader_Original                               = nullptr;
D3D11_CSSetShader_pfn                               D3D11_CSSetShader_Original                               = nullptr;

D3D11_VSGetShader_pfn                               D3D11_VSGetShader_Original                               = nullptr;
D3D11_PSGetShader_pfn                               D3D11_PSGetShader_Original                               = nullptr;
D3D11_GSGetShader_pfn                               D3D11_GSGetShader_Original                               = nullptr;
D3D11_HSGetShader_pfn                               D3D11_HSGetShader_Original                               = nullptr;
D3D11_DSGetShader_pfn                               D3D11_DSGetShader_Original                               = nullptr;
D3D11_CSGetShader_pfn                               D3D11_CSGetShader_Original                               = nullptr;

D3D11_GetData_pfn                                   D3D11_GetData_Original                                   = nullptr;

D3D11_CopyResource_pfn                              D3D11_CopyResource_Original                              = nullptr;
D3D11_CopySubresourceRegion_pfn                     D3D11_CopySubresourceRegion_Original                     = nullptr;
D3D11_UpdateSubresource1_pfn                        D3D11_UpdateSubresource1_Original                        = nullptr;

//   0 QueryInterface
//   1 AddRef
//   2 Release

//   3 GetDevice
//   4 GetPrivateData
//   5 SetPrivateData
//   6 SetPrivateDataInterface

//   7 VSSetConstantBuffers
//   8 PSSetShaderResources
//   9 PSSetShader
//  10 PSSetSamplers
//  11 VSSetShader
//  12 DrawIndexed
//  13 Draw
//  14 Map
//  15 Unmap
//  16 PSSetConstantBuffers
//  17 IASetInputLayout
//  18 IASetVertexBuffers
//  19 IASetIndexBuffer
//  20 DrawIndexedInstanced
//  21 DrawInstanced
//  22 GSSetConstantBuffers
//  23 GSSetShader
//  24 IASetPrimitiveTopology
//  25 VSSetShaderResources
//  26 VSSetSamplers
//  27 Begin
//  28 End
//  29 GetData
//  30 SetPredication
//  31 GSSetShaderResources
//  32 GSSetSamplers
//  33 OMSetRenderTargets
//  34 OMSetRenderTargetsAndUnorderedAccessViews
//  35 OMSetBlendState
//  36 OMSetDepthStencilState
//  37 SOSetTargets
//  38 DrawAuto
//  39 DrawIndexedInstancedIndirect
//  40 DrawInstancedIndirect
//  41 Dispatch
//  42 DispatchIndirect
//  43 RSSetState
//  44 RSSetViewports
//  45 RSSetScissorRects
//  46 CopySubresourceRegion
//  47 CopyResource
//  48 UpdateSubresource
//  49 CopyStructureCount
//  50 ClearRenderTargetView
//  51 ClearUnorderedAccessViewUint
//  52 ClearUnorderedAccessViewFloat
//  53 ClearDepthStencilView
//  54 GenerateMips
//  55 SetResourceMinLOD
//  56 GetResourceMinLOD
//  57 ResolveSubresource
//  58 ExecuteCommandList
//  59 HSSetShaderResources
//  60 HSSetShader
//  61 HSSetSamplers
//  62 HSSetConstantBuffers
//  63 DSSetShaderResources
//  64 DSSetShader
//  65 DSSetSamplers
//  66 DSSetConstantBuffers
//  67 CSSetShaderResources
//  68 CSSetUnorderedAccessViews
//  69 CSSetShader
//  70 CSSetSamplers
//  71 CSSetConstantBuffers
//  72 VSGetConstantBuffers
//  73 PSGetShaderResources
//  74 PSGetShader
//  75 PSGetSamplers
//  76 VSGetShader
//  77 PSGetConstantBuffers
//  78 IAGetInputLayout
//  79 IAGetVertexBuffers
//  80 IAGetIndexBuffer
//  81 GSGetConstantBuffers
//  82 GSGetShader
//  83 IAGetPrimitiveTopology
//  84 VSGetShaderResources
//  85 VSGetSamplers
//  86 GetPredication
//  87 GSGetShaderResources
//  88 GSGetSamplers
//  89 OMGetRenderTargets
//  90 OMGetRenderTargetsAndUnorderedAccessViews
//  91 OMGetBlendState
//  92 OMGetDepthStencilState
//  93 SOGetTargets
//  94 RSGetState
//  95 RSGetViewports
//  96 RSGetScissorRects
//  97 HSGetShaderResources
//  98 HSGetShader
//  99 HSGetSamplers
// 100 HSGetConstantBuffers
// 101 DSGetShaderResources
// 102 DSGetShader
// 103 DSGetSamplers
// 104 DSGetConstantBuffers
// 105 CSGetShaderResources
// 106 CSGetUnorderedAccessViews
// 107 CSGetShader
// 108 CSGetSamplers
// 109 CSGetConstantBuffers
// 110 ClearState
// 111 Flush
// 112 GetType
// 113 GetContextFlags
// 114 FinishCommandList


#include <../src/render/d3d11/d3d11_dev_ctx.cpp>

__declspec (noinline)
HRESULT
STDMETHODCALLTYPE
D3D11_GetData_Override (
 _In_  ID3D11DeviceContext *This,
 _In_  ID3D11Asynchronous  *pAsync,
 _Out_writes_bytes_opt_   ( DataSize )
       void                *pData,
 _In_  UINT                 DataSize,
 _In_  UINT                 GetDataFlags )
{
  HRESULT hr =
    D3D11_GetData_Original (
    This,    pAsync,
      pData, DataSize,
          GetDataFlags     );
 
#if 1
  return hr;
#else
  dll_log.Log (L"Query Type: %lu, Misc Flags: %x - Result: %x, Value: %llu", qDesc.Query,
               qDesc.MiscFlags, hr, *(uint64_t *)pData);

  dll_log.Log (L"Query - Size: %lu", DataSize);

  if (pCounter)
  {
    dll_log.Log (L"Counter - Size: %lu", DataSize);
  }
  auto isDataReady =
   [&](void)
     -> bool
        {
          HRESULT hr =
            D3D11_GetData_Original (
              This, pAsync,
                    nullptr, 0,
                             GetDataFlags |
                             D3D11_ASYNC_GETDATA_DONOTFLUSH
                                   );
          return
            ( SUCCEEDED (hr) &&
                         hr  != S_FALSE );
        };


  auto finishGetData =
   [&](void)
     -> HRESULT
        {
          return
            D3D11_GetData_Original (
              This,    pAsync,
                pData, DataSize,
                    GetDataFlags
                                   );
        };
 
  extern bool
         __SK_DQXI_MakeAsyncObjectsGreatAgain;
  if ((! __SK_DQXI_MakeAsyncObjectsGreatAgain) ||
       (pData == nullptr && DataSize == 0)     ||
                           isDataReady ())
  {
    return
      finishGetData ();
  }
 
  int spins = 0;
 
  do
  {
    YieldProcessor ();
 
    if (++spins > 3)
    {
      break;
    }
  } while (! isDataReady ());

  return
    finishGetData ();
#endif
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_VSSetShader_Override (
 _In_     ID3D11DeviceContext        *This,
 _In_opt_ ID3D11VertexShader         *pVertexShader,
 _In_opt_ ID3D11ClassInstance *const *ppClassInstances,
          UINT                        NumClassInstances )
{
  return
    SK_D3D11_SetShader_Impl ( This, pVertexShader,
                                sk_shader_class::Vertex,
                                  ppClassInstances, NumClassInstances );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_VSGetShader_Override (
 _In_        ID3D11DeviceContext  *This,
 _Out_       ID3D11VertexShader  **ppVertexShader,
 _Out_opt_   ID3D11ClassInstance **ppClassInstances,
 _Inout_opt_ UINT                 *pNumClassInstances )
{
  return
    D3D11_VSGetShader_Original ( This, ppVertexShader,
                                 ppClassInstances, pNumClassInstances );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_PSSetShader_Override (
 _In_     ID3D11DeviceContext        *This,
 _In_opt_ ID3D11PixelShader          *pPixelShader,
 _In_opt_ ID3D11ClassInstance *const *ppClassInstances,
          UINT                        NumClassInstances )
{
  return
    SK_D3D11_SetShader_Impl ( This, pPixelShader,
                                sk_shader_class::Pixel,
                                  ppClassInstances, NumClassInstances );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_PSGetShader_Override (
 _In_        ID3D11DeviceContext  *This,
 _Out_       ID3D11PixelShader   **ppPixelShader,
 _Out_opt_   ID3D11ClassInstance **ppClassInstances,
 _Inout_opt_ UINT                 *pNumClassInstances )
{
  return D3D11_PSGetShader_Original ( This, ppPixelShader,
                                        ppClassInstances, pNumClassInstances );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_GSSetShader_Override (
 _In_     ID3D11DeviceContext        *This,
 _In_opt_ ID3D11GeometryShader       *pGeometryShader,
 _In_opt_ ID3D11ClassInstance *const *ppClassInstances,
          UINT                        NumClassInstances )
{
  return
    SK_D3D11_SetShader_Impl ( This, pGeometryShader,
                                sk_shader_class::Geometry,
                                  ppClassInstances, NumClassInstances );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_GSGetShader_Override (
 _In_        ID3D11DeviceContext   *This,
 _Out_       ID3D11GeometryShader **ppGeometryShader,
 _Out_opt_   ID3D11ClassInstance  **ppClassInstances,
 _Inout_opt_ UINT                  *pNumClassInstances )
{
  return
    D3D11_GSGetShader_Original (This, ppGeometryShader, ppClassInstances, pNumClassInstances);
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_HSSetShader_Override (
 _In_     ID3D11DeviceContext        *This,
 _In_opt_ ID3D11HullShader           *pHullShader,
 _In_opt_ ID3D11ClassInstance *const *ppClassInstances,
          UINT                        NumClassInstances )
{
  return
    SK_D3D11_SetShader_Impl ( This, pHullShader,
                                sk_shader_class::Hull,
                                  ppClassInstances, NumClassInstances );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_HSGetShader_Override (
 _In_        ID3D11DeviceContext  *This,
 _Out_       ID3D11HullShader    **ppHullShader,
 _Out_opt_   ID3D11ClassInstance **ppClassInstances,
 _Inout_opt_ UINT                 *pNumClassInstances )
{
  return
    D3D11_HSGetShader_Original ( This, ppHullShader,
                                   ppClassInstances, pNumClassInstances );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_DSSetShader_Override (
 _In_     ID3D11DeviceContext        *This,
 _In_opt_ ID3D11DomainShader         *pDomainShader,
 _In_opt_ ID3D11ClassInstance *const *ppClassInstances,
          UINT                        NumClassInstances )
{
  return
    SK_D3D11_SetShader_Impl ( This, pDomainShader,
                                sk_shader_class::Domain,
                                  ppClassInstances, NumClassInstances );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_DSGetShader_Override (
 _In_        ID3D11DeviceContext  *This,
 _Out_       ID3D11DomainShader  **ppDomainShader,
 _Out_opt_   ID3D11ClassInstance **ppClassInstances,
 _Inout_opt_ UINT                 *pNumClassInstances )
{
  return D3D11_DSGetShader_Original ( This, ppDomainShader,
                                        ppClassInstances, pNumClassInstances );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_CSSetShader_Override (
 _In_     ID3D11DeviceContext        *This,
 _In_opt_ ID3D11ComputeShader        *pComputeShader,
 _In_opt_ ID3D11ClassInstance *const *ppClassInstances,
          UINT                        NumClassInstances )
{
  return
    SK_D3D11_SetShader_Impl ( This, pComputeShader,
                                sk_shader_class::Compute,
                                  ppClassInstances, NumClassInstances );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_CSGetShader_Override (
 _In_        ID3D11DeviceContext  *This,
 _Out_       ID3D11ComputeShader **ppComputeShader,
 _Out_opt_   ID3D11ClassInstance **ppClassInstances,
 _Inout_opt_ UINT                 *pNumClassInstances )
{
  return
    D3D11_CSGetShader_Original ( This, ppComputeShader,
                                   ppClassInstances, pNumClassInstances );
}

using D3D11_PSSetShader_pfn =
  void (STDMETHODCALLTYPE *)( ID3D11DeviceContext        *This,
                     _In_opt_ ID3D11PixelShader          *pPixelShader,
                     _In_opt_ ID3D11ClassInstance *const *ppClassInstances,
                              UINT                        NumClassInstances );

using D3D11_GSSetShader_pfn =
  void (STDMETHODCALLTYPE *)( ID3D11DeviceContext        *This,
                     _In_opt_ ID3D11GeometryShader       *pGeometryShader,
                     _In_opt_ ID3D11ClassInstance *const *ppClassInstances,
                              UINT                        NumClassInstances );

using D3D11_HSSetShader_pfn =
  void (STDMETHODCALLTYPE *)( ID3D11DeviceContext        *This,
                     _In_opt_ ID3D11HullShader           *pHullShader,
                     _In_opt_ ID3D11ClassInstance *const *ppClassInstances,
                              UINT                        NumClassInstances );

using D3D11_DSSetShader_pfn =
  void (STDMETHODCALLTYPE *)( ID3D11DeviceContext        *This,
                     _In_opt_ ID3D11DomainShader         *pDomainShader,
                     _In_opt_ ID3D11ClassInstance *const *ppClassInstances,
                              UINT                        NumClassInstances );

using D3D11_CSSetShader_pfn =
  void (STDMETHODCALLTYPE *)( ID3D11DeviceContext        *This,
                     _In_opt_ ID3D11ComputeShader        *pComputeShader,
                     _In_opt_ ID3D11ClassInstance *const *ppClassInstances,
                              UINT                        NumClassInstances );


__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_RSSetScissorRects_Override (
        ID3D11DeviceContext *This,
        UINT                 NumRects,
  const D3D11_RECT          *pRects )
{
  return
    D3D11_RSSetScissorRects_Original (This, NumRects, pRects);
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_VSSetConstantBuffers_Override (
  ID3D11DeviceContext*  This,
  UINT                  StartSlot,
  UINT                  NumBuffers,
  ID3D11Buffer *const  *ppConstantBuffers )
{
  //dll_log.Log (L"[   DXGI   ] [!]D3D11_VSSetConstantBuffers (%lu, %lu, ...)", StartSlot, NumBuffers);
  return
    D3D11_VSSetConstantBuffers_Original (This, StartSlot, NumBuffers, ppConstantBuffers );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_PSSetConstantBuffers_Override (
  ID3D11DeviceContext*  This,
  UINT                  StartSlot,
  UINT                  NumBuffers,
  ID3D11Buffer *const  *ppConstantBuffers )
{
  //dll_log.Log (L"[   DXGI   ] [!]D3D11_VSSetConstantBuffers (%lu, %lu, ...)", StartSlot, NumBuffers);
  return
    D3D11_PSSetConstantBuffers_Original (This, StartSlot, NumBuffers, ppConstantBuffers );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_VSSetShaderResources_Override (
  _In_           ID3D11DeviceContext             *This,
  _In_           UINT                             StartSlot,
  _In_           UINT                             NumViews,
  _In_opt_       ID3D11ShaderResourceView* const *ppShaderResourceViews )
{
  SK_D3D11_SetShaderResources_Impl (
          SK_D3D11_ShaderType::Vertex,
    SK_D3D11_IsDevCtxDeferred (This),
                               This , nullptr,
      StartSlot,
        NumViews,
          ppShaderResourceViews    );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_PSSetShaderResources_Override (
  _In_           ID3D11DeviceContext             *This,
  _In_           UINT                             StartSlot,
  _In_           UINT                             NumViews,
  _In_opt_       ID3D11ShaderResourceView* const *ppShaderResourceViews )
{
  SK_D3D11_SetShaderResources_Impl (
          SK_D3D11_ShaderType::Pixel,
    SK_D3D11_IsDevCtxDeferred (This),
                               This , nullptr,
      StartSlot,
        NumViews,
          ppShaderResourceViews    );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_GSSetShaderResources_Override (
  _In_           ID3D11DeviceContext             *This,
  _In_           UINT                             StartSlot,
  _In_           UINT                             NumViews,
  _In_opt_       ID3D11ShaderResourceView* const *ppShaderResourceViews )
{
    SK_D3D11_SetShaderResources_Impl (
          SK_D3D11_ShaderType::Geometry,
    SK_D3D11_IsDevCtxDeferred (This),
                               This , nullptr,
      StartSlot,
        NumViews,
          ppShaderResourceViews    );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_HSSetShaderResources_Override (
  _In_           ID3D11DeviceContext             *This,
  _In_           UINT                             StartSlot,
  _In_           UINT                             NumViews,
  _In_opt_       ID3D11ShaderResourceView* const *ppShaderResourceViews )
{
  SK_D3D11_SetShaderResources_Impl (
          SK_D3D11_ShaderType::Hull,
    SK_D3D11_IsDevCtxDeferred (This),
                               This , nullptr,
      StartSlot,
        NumViews,
          ppShaderResourceViews    );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_DSSetShaderResources_Override (
  _In_           ID3D11DeviceContext             *This,
  _In_           UINT                             StartSlot,
  _In_           UINT                             NumViews,
  _In_opt_       ID3D11ShaderResourceView* const *ppShaderResourceViews )
{
  SK_D3D11_SetShaderResources_Impl (
          SK_D3D11_ShaderType::Domain,
    SK_D3D11_IsDevCtxDeferred (This),
                               This , nullptr,
      StartSlot,
        NumViews,
          ppShaderResourceViews    );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_CSSetShaderResources_Override (
  _In_           ID3D11DeviceContext             *This,
  _In_           UINT                             StartSlot,
  _In_           UINT                             NumViews,
  _In_opt_       ID3D11ShaderResourceView* const *ppShaderResourceViews )
{
  SK_D3D11_SetShaderResources_Impl (
          SK_D3D11_ShaderType::Compute,
    SK_D3D11_IsDevCtxDeferred (This),
                               This , nullptr,
      StartSlot,
        NumViews,
          ppShaderResourceViews    );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_CSSetUnorderedAccessViews_Override (
  _In_           ID3D11DeviceContext             *This,
  _In_           UINT                             StartSlot,
  _In_           UINT                             NumUAVs,
  _In_opt_       ID3D11UnorderedAccessView *const *ppUnorderedAccessViews,
  _In_opt_ const UINT                             *pUAVInitialCounts )
{
  return
    D3D11_CSSetUnorderedAccessViews_Original (This, StartSlot, NumUAVs, ppUnorderedAccessViews, pUAVInitialCounts);
}


__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_UpdateSubresource1_Override (
  _In_           ID3D11DeviceContext1 *This,
  _In_           ID3D11Resource       *pDstResource,
  _In_           UINT                  DstSubresource,
  _In_opt_ const D3D11_BOX            *pDstBox,
  _In_     const void                 *pSrcData,
  _In_           UINT                  SrcRowPitch,
  _In_           UINT                  SrcDepthPitch,
  _In_           UINT                  CopyFlags)
{
  bool early_out = false;

  SK_TLS *pTLS = nullptr;

  // UB: If it's happening, pretend we never saw this...
  if ( pDstResource == nullptr ||
       pSrcData     == nullptr    )
  {
    early_out = true;
  }

  else
  {
        early_out = (! SK_D3D11_ShouldTrackRenderOp (This, &pTLS));
    if (early_out)
    {
      early_out = (! SK_D3D11_ShouldTrackMMIO (This, &pTLS));
    }
  }


  if (early_out)
  {
    return
      D3D11_UpdateSubresource1_Original ( This, pDstResource, DstSubresource,
                                            pDstBox, pSrcData, SrcRowPitch,
                                              SrcDepthPitch, CopyFlags );
  }


  if (SK_D3D11_IsDevCtxDeferred (This))
  {
    return
      D3D11_UpdateSubresource1_Original ( This, pDstResource, DstSubresource,
                                            pDstBox, pSrcData, SrcRowPitch,
                                              SrcDepthPitch, CopyFlags );
  }


  dll_log.Log (L"UpdateSubresource1 ({%s}", SK_D3D11_DescribeResource (pDstResource).c_str ());


  //dll_log.Log (L"[   DXGI   ] [!]D3D11_UpdateSubresource1 (%ph, %lu, %ph, %ph, %lu, %lu, %x)",
  //          pDstResource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch, CopyFlags);

  D3D11_RESOURCE_DIMENSION rdim = D3D11_RESOURCE_DIMENSION_UNKNOWN;
  pDstResource->GetType  (&rdim);

  if (SK_D3D11_IsStagingCacheable (rdim, pDstResource) && DstSubresource == 0)
  {
    static auto& textures =
      SK_D3D11_Textures;

    CComQIPtr <ID3D11Texture2D> pTex (pDstResource);

    if (pTex != nullptr)
    {
      D3D11_TEXTURE2D_DESC desc = { };
           pTex->GetDesc (&desc);

      D3D11_SUBRESOURCE_DATA srd = { };

      srd.pSysMem           = pSrcData;
      srd.SysMemPitch       = SrcRowPitch;
      srd.SysMemSlicePitch  = 0;

      size_t   size         = 0;
      uint32_t top_crc32c   = 0x0;

      uint32_t checksum     =
        crc32_tex   (&desc, &srd, &size, &top_crc32c, false);

      const uint32_t cache_tag    =
        safe_crc32c (top_crc32c, (uint8_t *)(&desc), sizeof D3D11_TEXTURE2D_DESC);

      const auto start            = SK_QueryPerf ().QuadPart;

      CComPtr <ID3D11Texture2D> pCachedTex =
        textures.getTexture2D (cache_tag, &desc, nullptr, nullptr, pTLS);

      if (pCachedTex != nullptr)
      {
        CComQIPtr <ID3D11Resource> pCachedResource (pCachedTex);

        D3D11_CopyResource_Original (This, pDstResource, pCachedResource);

        SK_LOG1 ( ( L"Texture Cache Hit (Slow Path): (%lux%lu) -- %x",
                      desc.Width, desc.Height, top_crc32c ),
                    L"DX11TexMgr" );

        return;
      }

      else
      {
        if (SK_D3D11_TextureIsCached (pTex))
        {
          SK_LOG0 ( (L"Cached texture was updated (UpdateSubresource)... removing from cache! - <%s>",
                         SK_GetCallerName ().c_str ()), L"DX11TexMgr" );
          SK_D3D11_RemoveTexFromCache (pTex, true);
        }

        D3D11_UpdateSubresource_Original ( This, pDstResource, DstSubresource,
                                             pDstBox, pSrcData, SrcRowPitch,
                                               SrcDepthPitch );
        const auto end     = SK_QueryPerf ().QuadPart;
              auto elapsed = end - start;

        if (desc.Usage == D3D11_USAGE_STAGING)
        {
          auto&& map_ctx = mapped_resources [This];

          map_ctx.dynamic_textures  [pDstResource] = checksum;
          map_ctx.dynamic_texturesx [pDstResource] = top_crc32c;

          SK_LOG1 ( ( L"New Staged Texture: (%lux%lu) -- %x",
                        desc.Width, desc.Height, top_crc32c ),
                      L"DX11TexMgr" );

          map_ctx.dynamic_times2    [checksum]  = elapsed;
          map_ctx.dynamic_sizes2    [checksum]  = size;

          return;
        }

        else
        {
          bool cacheable = ( desc.MiscFlags <= 4 &&
                             desc.Width      > 0 &&
                             desc.Height     > 0 &&
                             desc.ArraySize == 1 //||
                           //((desc.ArraySize  % 6 == 0) && (desc.MiscFlags & D3D11_RESOURCE_MISC_TEXTURECUBE))
                           );

          bool compressed = false;

          if ( (desc.Format >= DXGI_FORMAT_BC1_TYPELESS  &&
                desc.Format <= DXGI_FORMAT_BC5_SNORM)    ||
               (desc.Format >= DXGI_FORMAT_BC6H_TYPELESS &&
                desc.Format <= DXGI_FORMAT_BC7_UNORM_SRGB) )
          {
            compressed = true;
          }

          // If this isn't an injectable texture, then filter out non-mipmapped
          //   textures.
          if (/*(! injectable) && */
              cache_opts.ignore_non_mipped)
            cacheable &= (desc.MipLevels > 1 || compressed);

          if (cacheable)
          {
            SK_LOG1 ( ( L"New Cacheable Texture: (%lux%lu) -- %x",
                          desc.Width, desc.Height, top_crc32c ),
                        L"DX11TexMgr" );

            textures.CacheMisses_2D++;
            textures.refTexture2D ( pTex, &desc, cache_tag, size, elapsed, top_crc32c,
                                      L"", nullptr, (HMODULE)(intptr_t)-1/*SK_GetCallingDLL ()*/, pTLS );

            return;
          }
        }
      }
    }
  }

  return D3D11_UpdateSubresource1_Original ( This, pDstResource, DstSubresource,
                                               pDstBox, pSrcData, SrcRowPitch,
                                                 SrcDepthPitch, CopyFlags );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_UpdateSubresource_Override (
  _In_           ID3D11DeviceContext* This,
  _In_           ID3D11Resource      *pDstResource,
  _In_           UINT                 DstSubresource,
  _In_opt_ const D3D11_BOX           *pDstBox,
  _In_     const void                *pSrcData,
  _In_           UINT                 SrcRowPitch,
  _In_           UINT                 SrcDepthPitch)
{
  SK_D3D11_UpdateSubresource_Impl ( This,
                                      pDstResource, DstSubresource,
                                        pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch,
                                          false );
}


__declspec (noinline)
HRESULT
STDMETHODCALLTYPE
D3D11_Map_Override (
     _In_ ID3D11DeviceContext      *This,
     _In_ ID3D11Resource           *pResource,
     _In_ UINT                      Subresource,
     _In_ D3D11_MAP                 MapType,
     _In_ UINT                      MapFlags,
_Out_opt_ D3D11_MAPPED_SUBRESOURCE *pMappedResource )
{
  return
    SK_D3D11_Map_Impl ( This,
                          pResource, Subresource,
                            MapType, MapFlags,
                              pMappedResource, false );
}


__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_Unmap_Override (
  _In_ ID3D11DeviceContext *This,
  _In_ ID3D11Resource      *pResource,
  _In_ UINT                 Subresource )
{
  SK_D3D11_Unmap_Impl (This, pResource, Subresource, false);
}



__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_CopyResource_Override (
       ID3D11DeviceContext *This,
  _In_ ID3D11Resource      *pDstResource,
  _In_ ID3D11Resource      *pSrcResource )
{
  SK_D3D11_CopyResource_Impl (This, pDstResource, pSrcResource, false);
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_CopySubresourceRegion_Override (
  _In_           ID3D11DeviceContext *This,
  _In_           ID3D11Resource      *pDstResource,
  _In_           UINT                 DstSubresource,
  _In_           UINT                 DstX,
  _In_           UINT                 DstY,
  _In_           UINT                 DstZ,
  _In_           ID3D11Resource      *pSrcResource,
  _In_           UINT                 SrcSubresource,
  _In_opt_ const D3D11_BOX           *pSrcBox )
{
  // UB: If it's happening, pretend we never saw this...
  if (pDstResource == nullptr || pSrcResource == nullptr)
  {
    return;
  }

  if (SK_D3D11_IsDevCtxDeferred (This))
  {
    return
      D3D11_CopySubresourceRegion_Original (This, pDstResource, DstSubresource, DstX, DstY, DstZ, pSrcResource, SrcSubresource, pSrcBox);
  }


  ///if (SK_GetCurrentGameID() == SK_GAME_ID::Ys_Eight)
  ///{
  ///  CComQIPtr <ID3D11Texture2D> pTex (pSrcResource);
  ///
  ///  if (pTex)
  ///  {
  ///    D3D11_BOX box = { };
  ///
  ///    if (pSrcBox != nullptr)
  ///        box = *pSrcBox;
  ///
  ///    else
  ///    {
  ///      D3D11_TEXTURE2D_DESC tex_desc = {};
  ///           pTex->GetDesc (&tex_desc);
  ///
  ///      box.left  = 0; box.right  = tex_desc.Width;
  ///      box.top   = 0; box.bottom = tex_desc.Height;
  ///      box.front = 0; box.back   = 1;
  ///    }
  ///
  ///    dll_log.Log ( L"CopySubresourceRegion:  { %s <%lu> [ %lu/%lu, %lu/%lu, %lu/%lu ] } -> { %s <%lu> (%lu,%lu,%lu) }",
  ///                    DescribeResource (pSrcResource).c_str (), SrcSubresource, box.left,box.right, box.top,box.bottom, box.front,box.back,
  ///                    DescribeResource (pDstResource).c_str (), DstSubresource, DstX, DstY, DstZ );
  ///  }
  ///}


  ///if ( (! config.render.dxgi.deferred_isolation)    &&
  ///          SK_D3D11_IsDevCtxDeferred (This) )
  ///{
  ///  return
  ///    D3D11_CopySubresourceRegion_Original ( This, pDstResource, DstSubresource,
  ///                                                   DstX, DstY, DstZ,
  ///                                                     pSrcResource, SrcSubresource,
  ///                                                       pSrcBox );
  ///}


  SK_TLS* pTLS = SK_TLS_Bottom ();

  CComQIPtr <ID3D11Texture2D> pDstTex (pDstResource);

  if (pDstTex != nullptr)
  {
    if (! SK_D3D11_IsTexInjectThread (pTLS))
    {
      //if (SK_GetCurrentGameID () == SK_GAME_ID::PillarsOfEternity2)
      //{
      //  extern          bool SK_POE2_NopSubresourceCopy;
      //  extern volatile LONG SK_POE2_SkippedCopies;
      //
      //  if (SK_POE2_NopSubresourceCopy)
      //  {
      //    D3D11_TEXTURE2D_DESC desc_out = { };
      //      pDstTex->GetDesc (&desc_out);
      //
      //    if (pSrcBox != nullptr)
      //    {
      //      dll_log.Log (L"Copy (%lu-%lu,%lu-%lu : %lu,%lu,%lu : %s : {%p,%p})",
      //        pSrcBox->left, pSrcBox->right, pSrcBox->top, pSrcBox->bottom,
      //          DstX, DstY, DstZ,
      //            SK_D3D11_DescribeUsage (desc_out.Usage),
      //              pSrcResource, pDstResource );
      //    }
      //
      //    else
      //    {
      //      dll_log.Log (L"Copy (%lu,%lu,%lu : %s)",
      //                   DstX, DstY, DstZ,
      //                   SK_D3D11_DescribeUsage (desc_out.Usage) );
      //    }
      //
      //    if (pSrcBox == nullptr || ( pSrcBox->right != 3840 || pSrcBox->bottom != 2160 ))
      //    {
      //      if (desc_out.Usage == D3D11_USAGE_STAGING || pSrcBox == nullptr)
      //      {
      //        InterlockedIncrement (&SK_POE2_SkippedCopies);
      //
      //        return;
      //      }
      //    }
      //  }
      //}

      if (DstSubresource == 0 && SK_D3D11_TextureIsCached (pDstTex))
      {
        SK_LOG0 ( (L"Cached texture was modified (CopySubresourceRegion)... removing from cache! - <%s>",
                       SK_GetCallerName ().c_str ()), L"DX11TexMgr" );
        SK_D3D11_RemoveTexFromCache (pDstTex, true);
      }
    }
  }


  // ImGui gets to pass-through without invoking the hook
  if (! SK_D3D11_ShouldTrackRenderOp (This, &pTLS))
  {
    D3D11_CopySubresourceRegion_Original (This, pDstResource, DstSubresource, DstX, DstY, DstZ, pSrcResource, SrcSubresource, pSrcBox);

    return;
  }


  D3D11_RESOURCE_DIMENSION res_dim = { };
  pSrcResource->GetType  (&res_dim);


  if (SK_D3D11_EnableMMIOTracking)
  {
    SK_D3D11_MemoryThreads.mark ();

    switch (res_dim)
    {
      case D3D11_RESOURCE_DIMENSION_UNKNOWN:
        mem_map_stats.last_frame.resource_types [D3D11_RESOURCE_DIMENSION_UNKNOWN]++;
        break;
      case D3D11_RESOURCE_DIMENSION_BUFFER:
      {
        mem_map_stats.last_frame.resource_types [D3D11_RESOURCE_DIMENSION_BUFFER]++;

        ID3D11Buffer* pBuffer = nullptr;

        if (SUCCEEDED (pSrcResource->QueryInterface <ID3D11Buffer> (&pBuffer)))
        {
          D3D11_BUFFER_DESC  buf_desc = { };
          pBuffer->GetDesc (&buf_desc);
          {
            ////std::lock_guard <SK_Thread_CriticalSection> auto_lock (cs_mmio);

            if (buf_desc.BindFlags & D3D11_BIND_INDEX_BUFFER)
              mem_map_stats.last_frame.buffer_types [0]++;
              //mem_map_stats.last_frame.index_buffers.insert (pBuffer);

            if (buf_desc.BindFlags & D3D11_BIND_VERTEX_BUFFER)
              mem_map_stats.last_frame.buffer_types [1]++;
              //mem_map_stats.last_frame.vertex_buffers.insert (pBuffer);

            if (buf_desc.BindFlags & D3D11_BIND_CONSTANT_BUFFER)
              mem_map_stats.last_frame.buffer_types [2]++;
              //mem_map_stats.last_frame.constant_buffers.insert (pBuffer);
          }

          mem_map_stats.last_frame.bytes_copied += buf_desc.ByteWidth;

          pBuffer->Release ();
        }
      } break;
      case D3D11_RESOURCE_DIMENSION_TEXTURE1D:
        mem_map_stats.last_frame.resource_types [D3D11_RESOURCE_DIMENSION_TEXTURE1D]++;
        break;
      case D3D11_RESOURCE_DIMENSION_TEXTURE2D:
        mem_map_stats.last_frame.resource_types [D3D11_RESOURCE_DIMENSION_TEXTURE2D]++;
        break;
      case D3D11_RESOURCE_DIMENSION_TEXTURE3D:
        mem_map_stats.last_frame.resource_types [D3D11_RESOURCE_DIMENSION_TEXTURE3D]++;
        break;
    }
  }


  D3D11_CopySubresourceRegion_Original (This, pDstResource, DstSubresource, DstX, DstY, DstZ, pSrcResource, SrcSubresource, pSrcBox);

  if ( ( SK_D3D11_IsStagingCacheable (res_dim, pSrcResource) ||
         SK_D3D11_IsStagingCacheable (res_dim, pDstResource) ) && SrcSubresource == 0 && DstSubresource == 0)
  {
    auto&& map_ctx = mapped_resources [This];

    if (pDstTex != nullptr && map_ctx.dynamic_textures.count (pSrcResource))
    {
      const uint32_t top_crc32 = map_ctx.dynamic_texturesx [pSrcResource];
      const uint32_t checksum  = map_ctx.dynamic_textures  [pSrcResource];

      D3D11_TEXTURE2D_DESC dst_desc = { };
        pDstTex->GetDesc (&dst_desc);

      const uint32_t cache_tag =
        safe_crc32c (top_crc32, (uint8_t *)(&dst_desc), sizeof D3D11_TEXTURE2D_DESC);

      if (checksum != 0x00 && dst_desc.Usage != D3D11_USAGE_STAGING)
      {
        static auto& textures =
          SK_D3D11_Textures;

        textures.refTexture2D ( pDstTex,
                                  &dst_desc,
                                    cache_tag,
                                      map_ctx.dynamic_sizes2   [checksum],
                                        map_ctx.dynamic_times2 [checksum],
                                          top_crc32,
                            L"", nullptr, (HMODULE)(intptr_t)-1/*SK_GetCallingDLL ()*/,
                                            pTLS );

        map_ctx.dynamic_textures.erase  (pSrcResource);
        map_ctx.dynamic_texturesx.erase (pSrcResource);

        map_ctx.dynamic_sizes2.erase    (checksum);
        map_ctx.dynamic_times2.erase    (checksum);
      }
    }
  }
}


__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_DrawAuto_Override (_In_ ID3D11DeviceContext *This)
{
  SK_LOG_FIRST_CALL

  SK_D3D11_DrawAuto_Impl ( This, false );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_DrawIndexed_Override (
  _In_ ID3D11DeviceContext *This,
  _In_ UINT                 IndexCount,
  _In_ UINT                 StartIndexLocation,
  _In_ INT                  BaseVertexLocation )
{
  SK_LOG_FIRST_CALL

  SK_D3D11_DrawIndexed_Impl ( This,
                                IndexCount, StartIndexLocation,
                                  BaseVertexLocation, false );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_Draw_Override (
  _In_ ID3D11DeviceContext *This,
  _In_ UINT                 VertexCount,
  _In_ UINT                 StartVertexLocation )
{
  SK_LOG_FIRST_CALL

  SK_D3D11_Draw_Impl (This, VertexCount, StartVertexLocation, false);
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_DrawIndexedInstanced_Override (
  _In_ ID3D11DeviceContext *This,
  _In_ UINT                 IndexCountPerInstance,
  _In_ UINT                 InstanceCount,
  _In_ UINT                 StartIndexLocation,
  _In_ INT                  BaseVertexLocation,
  _In_ UINT                 StartInstanceLocation )
{
  SK_LOG_FIRST_CALL

  SK_D3D11_DrawIndexedInstanced_Impl ( This,
                                         IndexCountPerInstance, InstanceCount,
                                         StartIndexLocation,    BaseVertexLocation,
                                         StartInstanceLocation, false );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_DrawIndexedInstancedIndirect_Override (
  _In_ ID3D11DeviceContext *This,
  _In_ ID3D11Buffer        *pBufferForArgs,
  _In_ UINT                 AlignedByteOffsetForArgs )
{
  SK_LOG_FIRST_CALL

  SK_D3D11_DrawIndexedInstancedIndirect_Impl (This, pBufferForArgs, AlignedByteOffsetForArgs, false);
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_DrawInstanced_Override (
  _In_ ID3D11DeviceContext *This,
  _In_ UINT                 VertexCountPerInstance,
  _In_ UINT                 InstanceCount,
  _In_ UINT                 StartVertexLocation,
  _In_ UINT                 StartInstanceLocation )
{
  SK_LOG_FIRST_CALL

  SK_D3D11_DrawInstanced_Impl ( This,
                                  VertexCountPerInstance, InstanceCount,
                                  StartVertexLocation, StartInstanceLocation, false );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_DrawInstancedIndirect_Override (
  _In_ ID3D11DeviceContext *This,
  _In_ ID3D11Buffer        *pBufferForArgs,
  _In_ UINT                 AlignedByteOffsetForArgs )
{
  SK_LOG_FIRST_CALL

  SK_D3D11_DrawInstancedIndirect_Impl (This, pBufferForArgs, AlignedByteOffsetForArgs, false);
}


__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_Dispatch_Override ( _In_ ID3D11DeviceContext *This,
                          _In_ UINT                 ThreadGroupCountX,
                          _In_ UINT                 ThreadGroupCountY,
                          _In_ UINT                 ThreadGroupCountZ )
{
  SK_LOG_FIRST_CALL

  SK_TLS *pTLS = nullptr;

  if (SK_D3D11_IsDevCtxDeferred (This) || (! SK_D3D11_ShouldTrackRenderOp (This, &pTLS)))
  {
    return
      D3D11_Dispatch_Original ( This,
                                  ThreadGroupCountX,
                                    ThreadGroupCountY,
                                      ThreadGroupCountZ );
  }

  if (SK_D3D11_DispatchHandler (This, pTLS))
    return;

  D3D11_Dispatch_Original ( This,
                              ThreadGroupCountX,
                                ThreadGroupCountY,
                                  ThreadGroupCountZ );

  SK_D3D11_PostDispatch (This, pTLS);
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_DispatchIndirect_Override ( _In_ ID3D11DeviceContext *This,
                                  _In_ ID3D11Buffer        *pBufferForArgs,
                                  _In_ UINT                 AlignedByteOffsetForArgs )
{
  SK_LOG_FIRST_CALL

  SK_TLS *pTLS = nullptr;

  if (SK_D3D11_IsDevCtxDeferred (This) || (! SK_D3D11_ShouldTrackRenderOp (This, &pTLS)))
  {
    return
      D3D11_DispatchIndirect_Original ( This,
                                          pBufferForArgs,
                                            AlignedByteOffsetForArgs );
  }

  if (SK_D3D11_DispatchHandler (This, pTLS))
    return;

 
  SK_ReShade_DrawCallback.call (This, 64, pTLS);

  D3D11_DispatchIndirect_Original ( This,
                                      pBufferForArgs,
                                        AlignedByteOffsetForArgs );

  SK_D3D11_PostDispatch (This, pTLS);
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_OMSetRenderTargets_Override (
         ID3D11DeviceContext           *This,
_In_     UINT                           NumViews,
_In_opt_ ID3D11RenderTargetView *const *ppRenderTargetViews,
_In_opt_ ID3D11DepthStencilView        *pDepthStencilView )
{
  SK_D3D11_OMSetRenderTargets_Impl ( This,
                                       NumViews, ppRenderTargetViews,
                                         pDepthStencilView, false );
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_OMSetRenderTargetsAndUnorderedAccessViews_Override ( ID3D11DeviceContext              *This,
                                            _In_           UINT                              NumRTVs,
                                            _In_opt_       ID3D11RenderTargetView    *const *ppRenderTargetViews,
                                            _In_opt_       ID3D11DepthStencilView           *pDepthStencilView,
                                            _In_           UINT                              UAVStartSlot,
                                            _In_           UINT                              NumUAVs,
                                            _In_opt_       ID3D11UnorderedAccessView *const *ppUnorderedAccessViews,
                                            _In_opt_ const UINT                             *pUAVInitialCounts )
{
  ID3D11DepthStencilView *pDSV = pDepthStencilView;

  if (SK_D3D11_IsDevCtxDeferred (This))
  {
    return
      D3D11_OMSetRenderTargetsAndUnorderedAccessViews_Original (
        This, NumRTVs, ppRenderTargetViews,
          pDSV, UAVStartSlot, NumUAVs,
            ppUnorderedAccessViews, pUAVInitialCounts
      );
  }

  SK_TLS *pTLS = nullptr;

  UINT dev_idx =
    SK_D3D11_GetDeviceContextHandle (This);

  if (pDepthStencilView != nullptr && SK_ReShade_SetDepthStencilViewCallback.fn != nullptr)
  {
    SK_ReShade_SetDepthStencilViewCallback.call (pDSV, pTLS);
  }

  // ImGui gets to pass-through without invoking the hook
  if (! SK_D3D11_ShouldTrackRenderOp (This, &pTLS))
  {
    for (auto&& i : tracked_rtv.active [dev_idx]) i.store (false);

    tracked_rtv.active_count [dev_idx] = 0;
 
    D3D11_OMSetRenderTargetsAndUnorderedAccessViews_Original (
      This, NumRTVs, ppRenderTargetViews,
        pDSV, UAVStartSlot, NumUAVs,
          ppUnorderedAccessViews, pUAVInitialCounts
    );

    return;
  }

  D3D11_OMSetRenderTargetsAndUnorderedAccessViews_Original (
    This, NumRTVs, ppRenderTargetViews,
      pDSV, UAVStartSlot, NumUAVs,
        ppUnorderedAccessViews, pUAVInitialCounts
  );

  if (NumRTVs > 0)
  {
    if (ppRenderTargetViews)
    {
      auto&                              rt_views =
        SK_D3D11_RenderTargets [dev_idx].rt_views;

      const auto* tracked_rtv_res =
        static_cast <ID3D11RenderTargetView *> (
          ReadPointerAcquire ((volatile PVOID *)&tracked_rtv.resource)
        );

      for (UINT i = 0; i < NumRTVs; i++)
      {
        if (ppRenderTargetViews [i] && rt_views.emplace (ppRenderTargetViews [i]).second)
            ppRenderTargetViews [i]->AddRef ();

        const bool active_before = tracked_rtv.active_count [dev_idx] > 0 ?
                                   tracked_rtv.active       [dev_idx][i].load ()
                                                                    : false;

        const bool active =
          ( tracked_rtv_res == ppRenderTargetViews [i] ) ?
                       true :
                              false;

        if (active_before != active)
        {
          tracked_rtv.active [dev_idx][i] = active;

          if      (            active                    ) tracked_rtv.active_count [dev_idx]++;
          else if (tracked_rtv.active_count [dev_idx] > 0) tracked_rtv.active_count [dev_idx]--;
        }
      }
    }

    if (pDepthStencilView)
    {
      auto& ds_views =
        SK_D3D11_RenderTargets [dev_idx].ds_views;

      if (! ds_views.count (pDepthStencilView))
      {
                         pDepthStencilView->AddRef ();
        ds_views.insert (pDepthStencilView);
      }
    }
  }
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_OMGetRenderTargets_Override (ID3D11DeviceContext     *This,
                              _In_ UINT                     NumViews,
                             _Out_ ID3D11RenderTargetView **ppRenderTargetViews,
                             _Out_ ID3D11DepthStencilView **ppDepthStencilView)
{
  D3D11_OMGetRenderTargets_Original (This, NumViews, ppRenderTargetViews, ppDepthStencilView);

  if (ppDepthStencilView != nullptr && SK_ReShade_GetDepthStencilViewCallback.fn != nullptr)
  {
    if (! SK_D3D11_IsDevCtxDeferred (This))
      SK_ReShade_GetDepthStencilViewCallback.try_call (*ppDepthStencilView);
  }
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_OMGetRenderTargetsAndUnorderedAccessViews_Override (ID3D11DeviceContext        *This,
                                                    _In_  UINT                        NumRTVs,
                                                    _Out_ ID3D11RenderTargetView    **ppRenderTargetViews,
                                                    _Out_ ID3D11DepthStencilView    **ppDepthStencilView,
                                                    _In_  UINT                        UAVStartSlot,
                                                    _In_  UINT                        NumUAVs,
                                                    _Out_ ID3D11UnorderedAccessView **ppUnorderedAccessViews)
{
  D3D11_OMGetRenderTargetsAndUnorderedAccessViews_Original (This, NumRTVs, ppRenderTargetViews, ppDepthStencilView, UAVStartSlot, NumUAVs, ppUnorderedAccessViews);

  if (ppDepthStencilView != nullptr && SK_ReShade_GetDepthStencilViewCallback.fn != nullptr)
    SK_ReShade_GetDepthStencilViewCallback.try_call (*ppDepthStencilView);
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_ClearDepthStencilView_Override (ID3D11DeviceContext    *This,
                                 _In_ ID3D11DepthStencilView *pDepthStencilView,
                                 _In_ UINT                    ClearFlags,
                                 _In_ FLOAT                   Depth,
                                 _In_ UINT8                   Stencil)
{
  if (SK_ReShade_ClearDepthStencilViewCallback.fn != nullptr)
    SK_ReShade_ClearDepthStencilViewCallback.try_call (pDepthStencilView);

  D3D11_ClearDepthStencilView_Original (This, pDepthStencilView, ClearFlags, Depth, Stencil);
}

__declspec (noinline)
void
STDMETHODCALLTYPE
D3D11_RSSetViewports_Override (
        ID3D11DeviceContext* This,
        UINT                 NumViewports,
  const D3D11_VIEWPORT*      pViewports )
{
  D3D11_RSSetViewports_Original (This, NumViewports, pViewports);
}

void
WINAPI
D3D11_PSSetSamplers_Override
(
  _In_     ID3D11DeviceContext       *This,
  _In_     UINT                       StartSlot,
  _In_     UINT                       NumSamplers,
  _In_opt_ ID3D11SamplerState *const *ppSamplers )
{
  if (SK_D3D11_IsDevCtxDeferred (This))
  {
    return
      D3D11_PSSetSamplers_Original (This, StartSlot, NumSamplers, ppSamplers);
  }

#if 0
  if ( ppSamplers != nullptr )
  {
    //if (SK_GetCurrentRenderBackend ().d3d11.immediate_ctx.IsEqualObject (This))
    if (SK_GetCurrentRenderBackend ().device.p != nullptr)
    {
      SK_TLS *pTLS =
        SK_TLS_Bottom ();

      ID3D11SamplerState** pSamplerCopy =
        (ID3D11SamplerState **)pTLS->scratch_memory.cmd.alloc (
           sizeof (ID3D11SamplerState  *) * 4096
        );

      bool ys8_wrap_ui  = false,
           ys8_clamp_ui = false;

      if (SK_GetCurrentGameID () == SK_GAME_ID::Ys_Eight)
      {
        SK_D3D11_EnableTracking = true;

        auto HashFromCtx =
          [] ( std::array <uint32_t, SK_D3D11_MAX_DEV_CONTEXTS+1>& registry,
               UINT                                                dev_idx ) ->
        uint32_t
        {
          return registry [dev_idx];
        };

        UINT dev_idx = SK_D3D11_GetDeviceContextHandle (This);

        uint32_t current_ps = HashFromCtx (SK_D3D11_Shaders.pixel.current.shader,  dev_idx);
        uint32_t current_vs = HashFromCtx (SK_D3D11_Shaders.vertex.current.shader, dev_idx);

        switch (current_ps)
        {
          case 0x66b35959:
          case 0x9d665ae2:
          case 0xb21c8ab9:
          case 0x05da09bd:
          {
            if (current_ps == 0x66b35959 && b_66b35959)                             ys8_clamp_ui = true;
            if (current_ps == 0x9d665ae2 && b_9d665ae2)                             ys8_clamp_ui = true;
            if (current_ps == 0xb21c8ab9 && b_b21c8ab9)                             ys8_clamp_ui = true;
            if (current_ps == 0x05da09bd && b_05da09bd && current_vs == 0x7759c300) ys8_clamp_ui = true;
          }break;
          case 0x6bb0972d:
          {
            if (current_ps == 0x6bb0972d && b_6bb0972d) ys8_wrap_ui = true;
          } break;
        }
      }

      if (! (pTLS->imgui.drawing || ys8_clamp_ui || ys8_wrap_ui))
      {
        for ( UINT i = 0 ; i < NumSamplers ; i++ )
        {
          pSamplerCopy [i] = ppSamplers [i];

          if (ppSamplers [i] != nullptr)
          {
            D3D11_SAMPLER_DESC        new_desc = { };
            ppSamplers [i]->GetDesc (&new_desc);

            ((ID3D11Device *)SK_GetCurrentRenderBackend ().device.p)->CreateSamplerState (
                                                     &new_desc,
                                                       &pSamplerCopy [i] );
          }
        }
      }

      else
      {
        for ( UINT i = 0 ; i < NumSamplers ; i++ )
        {
          if (! ys8_wrap_ui)
            pSamplerCopy [i] = pTLS->d3d11.uiSampler_clamp;
          else
            pSamplerCopy [i] = pTLS->d3d11.uiSampler_wrap;
        }
      }

      return
        D3D11_PSSetSamplers_Original (This, StartSlot, NumSamplers, pSamplerCopy);
    }
  }
#endif

  D3D11_PSSetSamplers_Original (This, StartSlot, NumSamplers, ppSamplers);
}