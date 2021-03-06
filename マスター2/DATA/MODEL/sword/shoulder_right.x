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
 13;
 1.42000;0.32000;-0.08000;,
 -7.84000;-8.20000;-5.58000;,
 -6.74000;-0.82000;-6.30000;,
 -4.64000;1.94000;0.08000;,
 -10.46000;-1.60000;0.08000;,
 -6.42000;-0.96000;4.68000;,
 -6.40000;-20.06000;-0.40000;,
 -8.02000;-8.24000;4.78000;,
 -12.32000;-6.40000;0.16000;,
 -13.66000;-18.78000;-0.16000;,
 -9.80000;-19.40000;-3.94000;,
 -9.76000;-19.46000;3.60000;,
 -10.42000;-22.20000;-0.20000;;
 
 22;
 3;0,1,2;,
 3;3,0,2;,
 3;3,2,4;,
 3;3,5,0;,
 3;6,1,0;,
 3;1,4,2;,
 3;7,0,5;,
 3;3,4,5;,
 3;1,8,4;,
 3;7,6,0;,
 3;8,1,9;,
 3;4,7,5;,
 3;7,8,9;,
 3;9,1,10;,
 3;8,7,4;,
 3;6,10,1;,
 3;7,9,11;,
 3;7,11,6;,
 3;12,9,10;,
 3;12,11,9;,
 3;12,6,11;,
 3;12,10,6;;
 
 MeshMaterialList {
  78;
  22;
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3;;
  Material {
   0.414400;0.225600;0.000000;1.000000;;
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
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "C:\\Users\\game339\\Desktop\\卒業制作\\Team_a\\DATA\\TEX\\white.png";
   }
  }
  Material {
   0.248000;0.006400;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.062400;0.062400;0.062400;1.000000;;
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
    "C:\\Users\\game339\\Desktop\\卒業制作\\Team_a\\DATA\\TEX\\sword_face.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "33A109D9_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "1D733E9_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "1D733E9_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "4027A24D_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "4027A24D_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "298AA9E5_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "581C1289_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "572DE0CE_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "15FB1D0E_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "9D0B196_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "33A109D9_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "33A109D9_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "E95B21_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "E95B21_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "34B3A6CC_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "733B1EBE_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "13D26875_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "ocarina.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "2B399230_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "E95B21_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "E95B21_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "DFA86F8_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "63297E4D_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "42229DB7_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "42229DB7_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "42229DB7_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "42229DB7_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "753D63FC_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "753D63FC_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "753D63FC_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "753D63FC_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "753D63FC_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "753D63FC_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "733B1EBE_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "581C1289_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "581C1289_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "292EE278_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "266C7826_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "53D593AC_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "34B3A6CC_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "33A109D9_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "33A109D9_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "17F3DC0A_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "17F3DC0A_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "13D26875_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "9D0B196_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "9D0B196_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "7C094CAB_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "7C094CAB_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "6F09A424_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "6F09A424_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "6CFACF9E_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "5E6C5AF2_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "1F5CC19_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "1D733E9_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "1D733E9_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "1A2E4766_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "1A2E4766_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "1A2E4766_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "1A2E4766_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "1A2E4766_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "1A2E4766_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "1A2E4766_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "1A2E4766_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "1A2E4766_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "1A2E4766_c.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "skin.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "hair.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "skin.png";
   }
  }
  Material {
   0.470400;0.470400;0.470400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "skin.png";
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
  29;
  0.630941;-0.202224;-0.749012;,
  0.648511;-0.208763;-0.732019;,
  0.612362;-0.166670;-0.772809;,
  -0.294837;0.947791;-0.121506;,
  -0.755993;0.583651;-0.296354;,
  0.431134;0.388222;0.814498;,
  0.599437;-0.429201;-0.675620;,
  0.631562;-0.179392;0.754287;,
  -0.746011;0.184092;-0.639982;,
  -0.732310;-0.161983;-0.661425;,
  -0.692278;-0.295128;-0.658522;,
  -0.689491;-0.293802;0.662029;,
  -0.616528;-0.577824;-0.534801;,
  0.219925;0.866872;-0.447400;,
  -0.157093;0.924200;-0.348103;,
  0.224577;0.782764;0.580384;,
  0.523798;0.165928;0.835526;,
  -0.769818;0.117337;-0.627385;,
  -0.865321;0.080716;-0.494676;,
  -0.671899;0.531113;0.516208;,
  0.624795;-0.419051;0.658807;,
  -0.703624;0.219749;0.675739;,
  -0.707098;0.133054;0.694485;,
  -0.688998;0.163004;0.706195;,
  -0.709854;-0.173967;0.682527;,
  0.563659;-0.523465;-0.638962;,
  0.622424;-0.504376;0.598492;,
  -0.612750;-0.586693;0.529461;,
  0.469037;-0.882953;-0.019947;;
  22;
  3;0,1,2;,
  3;3,13,14;,
  3;3,14,4;,
  3;15,5,16;,
  3;6,1,0;,
  3;17,4,18;,
  3;7,16,5;,
  3;3,4,19;,
  3;17,8,4;,
  3;7,20,16;,
  3;8,17,9;,
  3;21,22,19;,
  3;22,23,24;,
  3;9,17,10;,
  3;23,22,21;,
  3;6,25,1;,
  3;22,24,11;,
  3;7,26,20;,
  3;12,9,10;,
  3;27,11,24;,
  3;28,20,26;,
  3;28,25,6;;
 }
 MeshTextureCoords {
  13;
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;;
 }
}
