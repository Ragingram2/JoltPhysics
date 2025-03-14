// Jolt Physics Library (https://github.com/jrouwe/JoltPhysics)
// SPDX-FileCopyrightText: 2024 Jorrit Rouwe
// SPDX-License-Identifier: MIT

#pragma once

#include <Renderer/DX12/RendererDX12.h>
#include <Renderer/RenderInstances.h>

class RenderPrimitive;

/// DirectX 12 implementation of a render instances object
class RenderInstancesDX12 : public RenderInstances
{
public:
	/// Constructor
							RenderInstancesDX12(RendererDX12 *inRenderer)										: mRenderer(inRenderer) { }
	virtual					~RenderInstancesDX12() override														{ Clear(); }

	/// Erase all instance data
	virtual void			Clear() override;

	/// Instance buffer management functions
	virtual void			CreateBuffer(int inNumInstances, int inInstanceSize) override;
	virtual void *			Lock() override;
	virtual void			Unlock() override;

	/// Draw the instances when context has been set by Renderer::BindShader
	virtual void			Draw(RenderPrimitive *inPrimitive, int inStartInstance, int inNumInstances) const override;

private:
	RendererDX12 *			mRenderer;

	ComPtr<ID3D12Resource>	mInstanceBuffer;
	uint					mInstanceBufferSize = 0;
	int						mInstanceSize = 0;
};
