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
 15;
 9.62665;-2.98281;4.58704;,
 11.11088;0.64048;-1.12126;,
 0.62280;-0.02967;-2.20172;,
 0.00319;-1.81586;1.62172;,
 0.62280;-0.02967;-2.20172;,
 11.11088;0.64048;-1.12126;,
 10.80823;2.39959;3.25517;,
 0.38597;1.44097;0.95401;,
 0.00319;-1.81586;1.62172;,
 10.80823;2.39959;3.25517;,
 9.62665;-2.98281;4.58704;,
 0.38597;1.44097;0.95401;,
 9.62665;-2.98281;4.58704;,
 10.80823;2.39959;3.25517;,
 11.11088;0.64048;-1.12126;;
 
 7;
 3;2,1,0;,
 3;3,2,0;,
 3;6,5,4;,
 3;7,6,4;,
 3;10,9,8;,
 3;9,11,8;,
 3;14,13,12;;
 
 MeshMaterialList {
  7;
  7;
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "C:\\Users\\game339\\Desktop\\Nintendo 64 - Super Smash Bros - Ness\\nes_face.png";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.018824;0.332549;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.458039;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.781176;0.762353;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "C:\\Users\\game339\\Desktop\\ë≤ã∆êßçÏ\\team_Prototype\\DATA\\TEX\\IMG_2227.JPG";
   }
  }
  Material {
   0.774902;0.652549;0.505098;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  10;
  0.063580;-0.881544;-0.467802;,
  0.107252;-0.851793;-0.512782;,
  0.019602;-0.907049;-0.420569;,
  -0.005486;0.917315;-0.398124;,
  0.009736;0.906643;-0.421786;,
  -0.020703;0.927156;-0.374102;,
  -0.240317;0.252826;0.937191;,
  -0.250720;0.284041;0.925451;,
  -0.229620;0.221302;0.947787;,
  0.973868;-0.179292;0.139414;;
  7;
  3;0,1,0;,
  3;2,0,0;,
  3;3,5,3;,
  3;4,3,3;,
  3;7,6,6;,
  3;6,8,6;,
  3;9,9,9;;
 }
 MeshTextureCoords {
  15;
  0.564900;0.321100;,
  0.564900;0.321100;,
  0.532400;0.325100;,
  0.532400;0.325100;,
  0.398300;0.243800;,
  0.325100;0.280400;,
  0.325100;0.280400;,
  0.398300;0.243800;,
  0.434800;1.016000;,
  0.353600;0.987500;,
  0.353600;0.987500;,
  0.434800;1.016000;,
  1.028200;0.544600;,
  1.028200;0.544600;,
  1.028200;0.544600;;
 }
}
