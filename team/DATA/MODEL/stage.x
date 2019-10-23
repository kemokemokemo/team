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
 70;
 -2919.60688;4.85659;-268.62781;,
 -1459.80344;4.85659;-268.62781;,
 -1459.80344;-37.16342;-268.62781;,
 -2919.60688;-37.16342;-268.62781;,
 0.00000;4.85659;-268.62781;,
 0.00000;-37.16342;-268.62781;,
 1459.80344;4.85659;-268.62781;,
 1459.80344;-37.16342;-268.62781;,
 2919.60688;4.85659;-268.62781;,
 2919.60688;-37.16342;-268.62781;,
 -1459.80344;-79.18342;-268.62781;,
 -2919.60688;-79.18342;-268.62781;,
 0.00000;-79.18342;-268.62781;,
 1459.80344;-79.18342;-268.62781;,
 2919.60688;-79.18342;-268.62781;,
 -1459.80344;-121.20342;-268.62781;,
 -1557.33752;-121.20342;-268.62781;,
 0.00000;-121.20342;-268.62781;,
 1459.80344;-121.20342;-268.62781;,
 1547.17229;-121.20342;-268.62781;,
 2919.60688;4.85659;-268.62781;,
 2919.60688;4.85659;268.62781;,
 2919.60688;-37.16342;268.62781;,
 2919.60688;-37.16342;-268.62781;,
 2919.60688;-79.18342;268.62781;,
 2919.60688;-79.18342;-268.62781;,
 1547.17229;-121.20342;268.62781;,
 1547.17229;-121.20342;-268.62781;,
 2919.60688;4.85659;268.62781;,
 1459.80344;4.85659;268.62781;,
 1459.80344;-37.16342;268.62781;,
 2919.60688;-37.16342;268.62781;,
 0.00000;4.85659;268.62781;,
 0.00000;-37.16342;268.62781;,
 -1459.80344;4.85659;268.62781;,
 -1459.80344;-37.16342;268.62781;,
 -2919.60688;4.85659;268.62781;,
 -2919.60688;-37.16342;268.62781;,
 1459.80344;-79.18342;268.62781;,
 2919.60688;-79.18342;268.62781;,
 0.00000;-79.18342;268.62781;,
 -1459.80344;-79.18342;268.62781;,
 -2919.60688;-79.18342;268.62781;,
 1459.80344;-121.20342;268.62781;,
 1547.17229;-121.20342;268.62781;,
 0.00000;-121.20342;268.62781;,
 -1459.80344;-121.20342;268.62781;,
 -1557.33752;-121.20342;268.62781;,
 -2919.60688;4.85659;268.62781;,
 -2919.60688;4.85659;-268.62781;,
 -2919.60688;-37.16342;-268.62781;,
 -2919.60688;-37.16342;268.62781;,
 -2919.60688;-79.18342;-268.62781;,
 -2919.60688;-79.18342;268.62781;,
 -1557.33752;-121.20342;-268.62781;,
 -1557.33752;-121.20342;268.62781;,
 -1459.80344;4.85659;268.62781;,
 -1459.80344;4.85659;-268.62781;,
 -2919.60688;4.85659;-268.62781;,
 0.00000;4.85659;-268.62781;,
 1459.80344;4.85659;268.62781;,
 1459.80344;4.85659;-268.62781;,
 2919.60688;4.85659;-268.62781;,
 -1557.33752;-121.20342;-268.62781;,
 -1459.80344;-121.20342;-268.62781;,
 -1459.80344;-121.20342;268.62781;,
 0.00000;-121.20342;-268.62781;,
 1459.80344;-121.20342;-268.62781;,
 1459.80344;-121.20342;268.62781;,
 1547.17229;-121.20342;-268.62781;;
 
 38;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;3,2,10,11;,
 4;2,5,12,10;,
 4;5,7,13,12;,
 4;7,9,14,13;,
 4;11,10,15,16;,
 4;10,12,17,15;,
 4;12,13,18,17;,
 4;13,14,19,18;,
 4;20,21,22,23;,
 4;23,22,24,25;,
 4;25,24,26,27;,
 4;28,29,30,31;,
 4;29,32,33,30;,
 4;32,34,35,33;,
 4;34,36,37,35;,
 4;31,30,38,39;,
 4;30,33,40,38;,
 4;33,35,41,40;,
 4;35,37,42,41;,
 4;39,38,43,44;,
 4;38,40,45,43;,
 4;40,41,46,45;,
 4;41,42,47,46;,
 4;48,49,50,51;,
 4;51,50,52,53;,
 4;53,52,54,55;,
 4;48,56,57,58;,
 4;56,32,59,57;,
 4;32,60,61,59;,
 4;60,21,62,61;,
 4;63,64,65,55;,
 4;64,66,45,65;,
 4;66,67,68,45;,
 4;67,69,26,68;;
 
 MeshMaterialList {
  1;
  38;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  10;
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  0.015303;-0.999883;-0.000000;,
  0.030603;-0.999532;-0.000000;,
  -1.000000;0.000000;0.000000;,
  -0.030831;-0.999525;0.000000;,
  -0.015417;-0.999881;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;;
  38;
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;4,4,3,3;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;6,6,7,7;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;7,9,9,7;,
  4;9,9,9,9;,
  4;9,9,9,9;,
  4;9,3,3,9;;
 }
 MeshTextureCoords {
  70;
  0.000000;0.000000;,
  0.250000;0.000000;,
  0.250000;0.333333;,
  0.000000;0.333333;,
  0.500000;0.000000;,
  0.500000;0.333333;,
  0.750000;0.000000;,
  0.750000;0.333333;,
  1.000000;0.000000;,
  1.000000;0.333333;,
  0.250000;0.666667;,
  0.000000;0.666667;,
  0.500000;0.666667;,
  0.750000;0.666667;,
  1.000000;0.666667;,
  0.250000;1.000000;,
  0.000000;1.000000;,
  0.500000;1.000000;,
  0.750000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.333333;,
  0.000000;0.333333;,
  1.000000;0.666667;,
  0.000000;0.666667;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.250000;0.000000;,
  0.250000;0.333333;,
  0.000000;0.333333;,
  0.500000;0.000000;,
  0.500000;0.333333;,
  0.750000;0.000000;,
  0.750000;0.333333;,
  1.000000;0.000000;,
  1.000000;0.333333;,
  0.250000;0.666667;,
  0.000000;0.666667;,
  0.500000;0.666667;,
  0.750000;0.666667;,
  1.000000;0.666667;,
  0.250000;1.000000;,
  0.000000;1.000000;,
  0.500000;1.000000;,
  0.750000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.333333;,
  0.000000;0.333333;,
  1.000000;0.666667;,
  0.000000;0.666667;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.000000;1.000000;,
  0.500000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.500000;0.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  1.000000;0.000000;;
 }
}
