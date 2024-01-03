//struct VS_INPUT
//{
//	float4 position : POSITION;
//	//float4 color : COLOR;
//	float2 uv : TEXCOORD;
//};
//
//struct VS_OUTPUT
//{
//	float4 position : SV_POSITION;
//	//float4 color : COLOR;
//	float2 uv : TEXCOORD;
//};
//
//cbuffer TransformData : register(b0)
//{
//	float4 offset;
//}
//
////IA - VS - RS - PS - OM
//VS_OUTPUT VS(VS_INPUT input)
//{
//	VS_OUTPUT output;
//	output.position = input.position + offset;
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


//struct VS_IN
//{
//    float3 p : POSITION;
//    float2 t : TEXCOORD;
//};
//
//struct VS_OUT
//{
//    float4 p : SV_POSITION;
//    float2 t : TEXCOORD;
//};
//VS_OUT VS(VS_IN vIn)
//{
//    VS_OUT vOut = (VS_OUT)0;
//    vOut.p = float4(vIn.p.x, vIn.p.y, vIn.p.z, 1);
//    vOut.t = vIn.t;
//    return vOut;
//}
//
//
//Texture2D g_txDiffuse1 : register(t0);
//SamplerState sample0 : register(s0);
//
//float4 PS(VS_OUT vIn) : SV_Target
//{
//    return g_txDiffuse1.Sample(sample0, vIn.t);
//}

//struct VS_IN
//{
//    float4 p : POSITION;
//    float2 t : TEXCOORD;
//};
//
//struct VS_OUT
//{
//    float4 p : SV_POSITION;
//    float2 t : TEXCOORD;
//};
//
//VS_OUT VS(VS_IN input)
//{
//    VS_OUT vOut = (VS_OUT)0;
//    float x = (input.p.x / 800.0f) * 2.0f - 1.0f;
//    float y = -((input.p.y / 600.0f) * 2.0f - 1.0f);
//    vOut.p = float4(x, y, 0.5f, 1.0f); // ½ºÀ§Áñ¸µ
//    vOut.t = input.t;
//
//    return vOut;
//}
//
//
//Texture2D g_txDiffuse1 : register(t0);
//SamplerState sample0 : register(s0);
//
//float4 PS(VS_OUT vIn) : SV_Target
//{
//    return g_txDiffuse1.Sample(sample0, vIn.t);
//}

