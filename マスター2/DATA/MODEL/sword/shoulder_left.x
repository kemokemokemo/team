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
 -1.70000;0.28000;0.08000;,
 6.46000;-0.84000;-6.14000;,
 7.56000;-8.24000;-5.42000;,
 4.36000;1.90000;0.24000;,
 10.18000;-1.64000;0.24000;,
 6.14000;-1.00000;4.84000;,
 6.12000;-20.10000;-0.24000;,
 7.74000;-8.28000;4.94000;,
 12.04000;-6.42000;0.32000;,
 13.40000;-18.82000;-0.00000;,
 9.52000;-19.44000;-3.78000;,
 9.48000;-19.50000;3.76000;,
 10.16000;-22.24000;-0.04000;;
 
 22;
 3;0,1,2;,
 3;3,1,0;,
 3;3,4,1;,
 3;3,0,5;,
 3;6,0,2;,
 3;2,1,4;,
 3;7,5,0;,
 3;3,5,4;,
 3;2,4,8;,
 3;7,0,6;,
 3;8,9,2;,
 3;4,5,7;,
 3;7,9,8;,
 3;9,10,2;,
 3;8,4,7;,
 3;6,2,10;,
 3;7,11,9;,
 3;7,6,11;,
 3;12,10,9;,
 3;12,9,11;,
 3;12,11,6;,
 3;12,6,10;;
 
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
  -0.630826;-0.201997;-0.749170;,
  -0.648437;-0.208613;-0.732127;,
  -0.612115;-0.166211;-0.773103;,
  0.294721;0.948057;-0.119700;,
  0.755945;0.584014;-0.295760;,
  -0.431134;0.388222;0.814498;,
  -0.599188;-0.429752;-0.675490;,
  -0.631562;-0.179392;0.754287;,
  0.745395;0.185015;-0.640435;,
  0.731080;-0.161437;-0.662918;,
  0.690558;-0.294792;-0.660475;,
  0.687775;-0.293437;0.663974;,
  0.615464;-0.576789;-0.537140;,
  0.157079;0.925137;-0.345613;,
  -0.220258;0.867902;-0.445234;,
  -0.224577;0.782764;0.580384;,
  -0.523798;0.165928;0.835526;,
  0.769189;0.117626;-0.628102;,
  0.865432;0.080531;-0.494512;,
  0.671899;0.531113;0.516208;,
  -0.624501;-0.419690;0.658680;,
  0.703192;0.220137;0.676063;,
  0.706353;0.133389;0.695178;,
  0.708613;-0.173402;0.683958;,
  0.688333;0.163890;0.706638;,
  -0.563210;-0.524287;-0.638685;,
  -0.621915;-0.505338;0.598210;,
  0.611681;-0.585707;0.531784;,
  -0.467223;-0.883914;-0.019968;;
  22;
  3;0,2,1;,
  3;3,13,14;,
  3;3,4,13;,
  3;15,16,5;,
  3;6,0,1;,
  3;17,18,4;,
  3;7,5,16;,
  3;3,19,4;,
  3;17,4,8;,
  3;7,16,20;,
  3;8,9,17;,
  3;21,19,22;,
  3;22,23,24;,
  3;9,10,17;,
  3;24,21,22;,
  3;6,1,25;,
  3;22,11,23;,
  3;7,20,26;,
  3;12,10,9;,
  3;27,23,11;,
  3;28,26,20;,
  3;28,6,25;;
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
