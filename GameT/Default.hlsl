//struct VS_INPUT
//{
//	float4 position : POSITION;
//	float4 color : COLOR;
//	//float2 uv : TEXCOORD;
//};
//
//struct VS_OUTPUT
//{
//	float4 position : SV_POSITION;
//	float4 color : COLOR;
//	//float2 uv : TEXCOORD;
//};
//
//cbuffer TransformData : register(b0)
//{
//	row_major matrix matWorld;
//	row_major matrix matView;
//	row_major matrix matProjection;
//}
//
//// IA - VS - RS - PS - OM
//VS_OUTPUT VS(VS_INPUT input)
//{
//	VS_OUTPUT output;
//
//	// WVP
//	float4 position = mul(input.position, matWorld); // W
//	position = mul(position, matView); // V
//	position = mul(position, matProjection); // P
//
//	output.position = position;
//	output.uv = input.uv;
//
//	return output;
//}
//
//Texture2D texture0 : register(t0);
//Texture2D texture1 : register(t1);
//SamplerState sampler0 : register(s0);
//
//float4 PS(VS_OUTPUT input) : SV_Target
//{
//	float4 color = texture0.Sample(sampler0, input.uv);
//
//	return color;
//}

float4 VS_KGCA(in float4 p : POSITION) : SV_POSITION
{
    return p;
}

float4 PS(in float4 p : SV_POSITION) : SV_Target
{
	return float4(1,1,0,1);
}