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
 -10.41920;2.48480;3.46648;,
 -10.75632;0.49410;-1.48419;,
 -0.11975;-0.02292;-2.27587;,
 0.05664;1.41362;0.80213;,
 -0.11975;-0.02292;-2.27587;,
 -10.75632;0.49410;-1.48419;,
 -8.92117;-3.55158;4.94997;,
 0.49602;-1.75558;1.37587;,
 0.05664;1.41362;0.80213;,
 -8.92117;-3.55158;4.94997;,
 -10.41920;2.48480;3.46648;,
 0.49602;-1.75558;1.37587;,
 -10.41920;2.48480;3.46648;,
 -8.92117;-3.55158;4.94997;,
 -10.75632;0.49410;-1.48419;;
 
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
  0.001270;0.917256;-0.398295;,
  0.017233;0.927256;-0.374030;,
  -0.014695;0.906391;-0.422183;,
  -0.035454;-0.880309;-0.473074;,
  0.009027;-0.902834;-0.429894;,
  -0.079781;-0.853954;-0.514196;,
  0.287868;0.251445;0.924071;,
  0.263667;0.291418;0.919541;,
  0.311434;0.210917;0.926565;,
  -0.967776;-0.203829;0.147865;;
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
  0.325100;0.280400;,
  0.325100;0.280400;,
  0.398300;0.247900;,
  0.398300;0.247900;,
  0.532400;0.325100;,
  0.564900;0.321100;,
  0.564900;0.321100;,
  0.532400;0.325100;,
  0.438900;1.016000;,
  0.353600;0.987500;,
  0.353600;0.987500;,
  0.438900;1.016000;,
  1.028200;0.544600;,
  1.028200;0.544600;,
  1.028200;0.544600;;
 }
}
