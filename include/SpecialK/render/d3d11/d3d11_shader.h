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
#pragma once

#include <string>
#include <vector>
#include <utility>

#include <SpecialK/render/d3d11/d3d11_core.h>

enum class sk_shader_class : DWORD {
  Unknown  = 0x00,
  Vertex   = 0x01,
  Pixel    = 0x02,
  Geometry = 0x04,
  Hull     = 0x08,
  Domain   = 0x10,
  Compute  = 0x20,

  _PADDING = DWORD_MAX
};

struct shader_disasm_s {
  std::string       header = "";
  std::string       code   = "";
  std::string       footer = "";

  struct constant_buffer
  {
    std::string      name  = "";
    UINT             Slot  =  0;

    struct variable
    {
      std::string                name                =  "";
      D3D11_SHADER_VARIABLE_DESC var_desc            = { };
      D3D11_SHADER_TYPE_DESC     type_desc           = { };
      float                      default_value [128] = { };
    };

    using struct_ent =
      std::pair <std::vector <variable>, std::string>;

    std::vector <struct_ent> structs = { };
    size_t                   size    = 0UL;
  };

  std::vector <constant_buffer> cbuffers = { };
};

void* SK_D3D11_InitShaderMods  (void);
void  SK_D3D11_LoadShaderState (bool clear = true);

struct SK_ReShadeDrawCallback_s
{
  constexpr SK_ReShadeDrawCallback_s (void) = default;

  SK_ReShade_PresentCallback_pfn fn   = nullptr;
  void*                          data = nullptr;

  struct explict_draw_s
  {
    constexpr explict_draw_s (void) = default;

    void*                   ptr     = nullptr;
    ID3D11RenderTargetView* pRTV    = nullptr;
    bool                    pass    = false;
    int                     calls   = 0;
    ID3D11DeviceContext*    src_ctx = nullptr;
  } explicit_draw;
};

extern
SK_LazyGlobal <SK_ReShadeDrawCallback_s>
               SK_ReShade_PresentCallback;

  #define ShaderColorDecl(idx) {                                                \
  { ImGuiCol_Header,        ImColor::HSV ( ((idx) + 1) / 6.0f, 0.5f,  0.45f) }, \
  { ImGuiCol_HeaderHovered, ImColor::HSV ( ((idx) + 1) / 6.0f, 0.55f, 0.6f ) }, \
  { ImGuiCol_HeaderActive,  ImColor::HSV ( ((idx) + 1) / 6.0f, 0.6f,  0.6f ) } }


  static
  std::unordered_map < sk_shader_class,
                       std::tuple < std::pair <const ImGuiCol, const ImColor>,
                                    std::pair <const ImGuiCol, const ImColor>,
                                    std::pair <const ImGuiCol, const ImColor> > >
    SK_D3D11_ShaderColors =
      { { sk_shader_class::Unknown,  ShaderColorDecl (-1) },
        { sk_shader_class::Vertex,   ShaderColorDecl ( 0) },
        { sk_shader_class::Pixel,    ShaderColorDecl ( 1) },
        { sk_shader_class::Geometry, ShaderColorDecl ( 2) },
        { sk_shader_class::Hull,     ShaderColorDecl ( 3) },
        { sk_shader_class::Domain,   ShaderColorDecl ( 4) },
        { sk_shader_class::Compute,  ShaderColorDecl ( 5) } };


// Creates a temporary texture with an internal format (i.e. single-sampled or not typeless)
//   that can actually be drawn. The returned SRV holds a reference to the underlying texture,
//     just throw the SRV away and the temporary texture will self-destruct instead of leaking.
HRESULT
SK_D3D11_MakeDrawableCopy ( ID3D11Device              *pDevice,
                            ID3D11Texture2D           *pUndrawableTexture,
                            ID3D11RenderTargetView    *pUndrawableRenderTarget, // Optional
                            ID3D11ShaderResourceView **ppCopyView );

// Draws (ImGui) a list of shaders that contribute output to
//   the selected RTV
void SK_D3D11_ShaderModDlg_RTVContributors (void);
void SK_D3D11_LiveShaderView               (bool& can_scroll);