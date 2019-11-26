xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 24;
 0.80992;-0.32212;3.38900;,
 1.96992;-5.28212;5.58900;,
 3.98992;-5.24212;-5.55100;,
 2.16992;-0.36212;-2.95100;,
 1.64992;-10.42212;-4.63100;,
 -3.53008;-9.38212;-4.03100;,
 -3.01008;-4.54212;-5.35100;,
 1.96992;-5.28212;5.58900;,
 0.38992;-10.42212;4.64900;,
 1.64992;-10.42212;-4.63100;,
 3.98992;-5.24212;-5.55100;,
 -3.43008;-9.28212;3.78900;,
 -3.53008;-9.38212;-4.03100;,
 2.16992;-0.36212;-2.95100;,
 -3.01008;-4.54212;-5.35100;,
 -3.47008;0.09788;0.04900;,
 3.98992;-5.24212;-5.55100;,
 -4.93008;-6.52212;-2.31100;,
 0.80992;-0.32212;3.38900;,
 -5.01008;-6.54212;3.04900;,
 1.96992;-5.28212;5.58900;,
 -3.43008;-9.28212;3.78900;,
 0.38992;-10.42212;4.64900;,
 -3.53008;-9.38212;-4.03100;;
 
 19;
 3;0,1,2;,
 3;0,2,3;,
 3;4,5,6;,
 3;4,6,2;,
 3;7,8,9;,
 3;7,9,10;,
 3;8,11,12;,
 3;8,12,9;,
 3;13,14,15;,
 3;14,13,16;,
 3;14,17,15;,
 3;18,19,20;,
 3;19,18,15;,
 3;20,19,21;,
 3;19,15,17;,
 3;20,21,22;,
 3;17,23,21;,
 3;17,14,23;,
 3;17,21,19;;
 
 MeshMaterialList {
  8;
  19;
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
  Material {
   0.414118;0.225882;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.636800;0.458400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.097600;0.000000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.332549;0.000000;0.037647;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.247843;0.006275;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.062745;0.062745;0.062745;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "C:\\Users\\game339\\Desktop\\���Ɛ���\\Team_a\\DATA\\TEX\\sword_face.png";
   }
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  24;
  0.944282;0.271052;0.186716;,
  0.976866;-0.139579;0.162017;,
  0.980533;0.056086;0.188173;,
  0.948017;0.246043;0.201808;,
  -0.102025;-0.200175;-0.974434;,
  -0.535784;-0.168105;-0.827452;,
  -0.434261;0.209741;-0.876029;,
  0.941218;-0.312695;0.127795;,
  -0.731679;-0.681618;0.006546;,
  -0.799676;0.469207;-0.374650;,
  -0.973693;-0.104528;-0.202474;,
  -0.423789;0.272759;0.863716;,
  -0.011194;0.169615;-0.985447;,
  0.926242;-0.347585;0.145811;,
  -0.244824;-0.969551;-0.005602;,
  -0.501697;-0.865041;0.002166;,
  -0.199791;-0.979463;-0.027127;,
  -0.132979;0.612281;-0.779377;,
  -0.451602;0.378393;0.808006;,
  -0.328675;0.085488;0.940566;,
  -0.521997;0.448779;0.725339;,
  -0.299572;-0.024766;0.953752;,
  -0.988304;-0.151728;-0.015317;,
  -0.246935;-0.100357;0.963821;;
  19;
  3;0,1,2;,
  3;0,2,3;,
  3;4,5,6;,
  3;4,6,12;,
  3;1,7,13;,
  3;1,13,2;,
  3;14,8,15;,
  3;14,15,16;,
  3;17,6,9;,
  3;6,17,12;,
  3;6,10,9;,
  3;18,11,19;,
  3;11,18,20;,
  3;19,11,21;,
  3;22,9,10;,
  3;19,21,23;,
  3;10,15,8;,
  3;10,6,5;,
  3;10,8,22;;
 }
 MeshTextureCoords {
  24;
  0.729700;0.845700;,
  0.868400;0.517600;,
  1.045000;0.531300;,
  0.846100;0.855500;,
  0.915000;0.160200;,
  0.500800;0.183600;,
  0.491100;0.518600;,
  -0.119500;0.085900;,
  -0.016400;0.722700;,
  1.069200;0.656300;,
  1.174300;-0.011700;,
  0.084700;0.781300;,
  1.005500;0.777300;,
  0.266300;-0.008900;,
  0.000000;-0.410300;,
  0.460900;0.002800;,
  0.064100;-0.437600;,
  0.247800;-0.591900;,
  0.792400;-0.006000;,
  0.707600;-0.582100;,
  1.000000;-0.428800;,
  0.806500;-0.820400;,
  0.919600;-0.887800;,
  0.123900;-0.832100;;
 }
}