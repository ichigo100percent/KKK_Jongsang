struct VS_IN
{
	float3 p : POSITION;
	float2 t : TEXCOORD;
};

struct VS_OUT
{
	float4 p : SV_POSITION;
	float2 t : TEXCOORD;
};

cbuffer cb0
{
	matrix g_matWorld : packoffset(c0);
	matrix g_matView  : packoffset(c4);
	matrix g_matProj  : packoffset(c8);
};

VS_OUT VS(VS_IN vln)
{
	VS_OUT vOut = (VS_OUT)0;
	float4 vWorld = mul(float4(vln.p, 1.0f), g_matWorld);
	float4 vView = mul(vWorld, g_matView);
	float4 vProj = mul(vView, g_matProj);

	vOut.p = vProj;
	vOut.t = vln.t;
	return vOut;
}

Texture2D g_txDiffuse1 : register(t0);
SamplerState sample0 : register(s0);

float4 PS(VS_OUT vIn) : SV_Target
{
	//return g_txDiffuse1.Sample(sample0, vIn.t);
	return float4(1,1,1,1);
}