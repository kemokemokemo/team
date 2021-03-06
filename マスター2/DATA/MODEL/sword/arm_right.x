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
 12;
 -1.16000;-6.70000;-5.90000;,
 3.72000;-0.40000;-0.16000;,
 3.86000;-7.76000;-0.16000;,
 -0.14000;0.14000;-3.96000;,
 -0.02000;0.22000;3.74000;,
 -2.84000;0.38000;-0.04000;,
 -0.58000;-23.00000;-0.18000;,
 -3.12000;-22.74000;-3.08000;,
 -5.46000;-22.36000;-0.06000;,
 -3.12000;-22.74000;-0.12000;,
 -0.76000;-6.64000;5.44000;,
 -2.92000;-22.80000;2.64000;;
 
 20;
 3;0,1,2;,
 3;0,3,1;,
 3;4,2,1;,
 3;1,3,5;,
 3;5,4,1;,
 3;0,5,3;,
 3;6,7,0;,
 3;6,0,2;,
 3;0,8,5;,
 3;9,7,6;,
 3;8,0,7;,
 3;8,10,5;,
 3;9,8,7;,
 3;10,8,11;,
 3;4,10,2;,
 3;5,10,4;,
 3;10,11,6;,
 3;10,6,2;,
 3;9,6,11;,
 3;9,11,8;;
 
 MeshMaterialList {
  78;
  20;
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
  28;
  0.732601;-0.076592;-0.676335;,
  0.730526;0.054344;-0.680720;,
  0.740170;-0.097448;-0.665322;,
  0.705088;0.094197;-0.702835;,
  0.750550;0.042648;0.659436;,
  0.117840;0.992956;-0.012310;,
  0.722122;-0.206041;-0.660368;,
  0.727282;-0.204078;-0.655296;,
  -0.997656;0.052671;0.043682;,
  -0.131261;-0.991330;-0.006014;,
  -0.804320;0.104386;0.584956;,
  -0.729892;-0.020824;0.683245;,
  0.749930;-0.043336;0.660096;,
  0.722780;0.013749;0.690942;,
  0.118420;0.992746;0.020785;,
  0.117130;0.992079;-0.045390;,
  -0.841016;0.124877;-0.526402;,
  -0.977809;0.207252;0.030613;,
  -0.783902;0.274808;-0.556757;,
  -0.131119;-0.991367;0.000000;,
  -0.101994;-0.994760;-0.007111;,
  -0.791093;-0.010858;-0.611600;,
  -0.160414;-0.987038;-0.004912;,
  0.758135;-0.118415;0.641256;,
  -0.775466;0.229423;0.588233;,
  0.745169;-0.209311;0.633176;,
  0.738635;-0.211724;0.639993;,
  -0.131399;-0.991257;-0.012027;;
  20;
  3;0,1,2;,
  3;0,3,1;,
  3;4,12,13;,
  3;5,14,5;,
  3;5,15,5;,
  3;16,17,18;,
  3;6,7,0;,
  3;6,0,2;,
  3;16,8,17;,
  3;9,19,20;,
  3;8,16,21;,
  3;8,10,17;,
  3;9,22,19;,
  3;10,8,11;,
  3;4,23,12;,
  3;17,10,24;,
  3;23,25,26;,
  3;23,26,12;,
  3;9,20,27;,
  3;9,27,22;;
 }
 MeshTextureCoords {
  12;
  0.455400;-0.203100;,
  0.345200;0.007800;,
  0.177100;-0.100600;,
  0.561000;-0.072300;,
  0.547600;-0.065400;,
  1.000000;-0.018600;,
  0.000000;-0.579100;,
  0.096700;-0.616200;,
  0.187500;-0.648400;,
  0.093800;-0.614300;,
  0.439000;-0.194300;,
  0.089300;-0.611300;;
 }
}
