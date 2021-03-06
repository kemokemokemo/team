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
 19;
 -2.00000;-13.14000;6.76000;,
 3.86000;0.38000;3.78000;,
 -4.22000;0.98000;2.86000;,
 4.28000;-11.72000;0.34000;,
 -3.74000;-38.38000;4.26000;,
 -5.86000;-10.68000;0.56000;,
 -0.06000;-38.46000;-0.18000;,
 -5.78000;-38.30000;0.02000;,
 3.86000;0.38000;3.78000;,
 4.28000;-11.72000;0.34000;,
 -0.44000;-0.02000;-5.84000;,
 -4.22000;0.98000;2.86000;,
 -5.86000;-10.68000;0.56000;,
 -1.58000;-13.74000;-4.72000;,
 -0.06000;-38.46000;-0.18000;,
 -3.58000;-38.38000;-2.68000;,
 -5.78000;-38.30000;0.02000;,
 -2.12000;-13.28000;-3.86000;,
 -0.26000;-13.38000;-3.86000;;
 
 20;
 3;0,1,2;,
 3;1,0,3;,
 3;4,3,0;,
 3;0,2,5;,
 3;3,4,6;,
 3;4,5,7;,
 3;5,4,0;,
 3;8,9,10;,
 3;8,10,11;,
 3;10,12,11;,
 3;13,14,15;,
 3;13,15,16;,
 3;17,12,10;,
 3;17,16,12;,
 3;17,13,16;,
 3;17,10,13;,
 3;18,9,14;,
 3;18,10,9;,
 3;18,13,10;,
 3;18,14,13;;
 
 MeshMaterialList {
  78;
  20;
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4;;
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
  24;
  0.505025;-0.011572;0.863027;,
  0.360295;0.049162;0.931542;,
  -0.525044;0.148896;0.837949;,
  0.736217;-0.139674;0.662174;,
  0.742552;-0.126672;0.657702;,
  -0.998119;0.044930;-0.041708;,
  0.761574;-0.135929;0.633663;,
  -0.997797;0.015339;-0.064550;,
  0.743770;-0.021514;-0.668089;,
  0.573570;-0.113719;-0.811225;,
  0.567218;-0.114272;-0.815601;,
  -0.802028;0.018585;-0.596998;,
  0.631688;-0.106463;-0.767877;,
  -0.847098;0.009969;0.531343;,
  -0.875870;-0.002579;0.482541;,
  0.900669;0.147460;-0.408718;,
  0.780524;-0.016283;-0.624913;,
  0.082686;0.993497;-0.078269;,
  -0.839386;0.078032;-0.537905;,
  -0.888666;0.205822;-0.409768;,
  0.612728;-0.109704;-0.782642;,
  -0.818621;0.024713;-0.573802;,
  -0.775038;0.010599;-0.631826;,
  -0.767715;0.010548;-0.640704;;
  20;
  3;0,1,2;,
  3;1,0,3;,
  3;4,3,0;,
  3;13,2,5;,
  3;3,4,6;,
  3;14,5,7;,
  3;5,14,13;,
  3;15,16,8;,
  3;17,17,17;,
  3;18,5,19;,
  3;10,20,9;,
  3;21,22,23;,
  3;11,5,18;,
  3;11,23,5;,
  3;11,21,7;,
  3;11,18,21;,
  3;12,16,20;,
  3;12,8,16;,
  3;12,10,8;,
  3;12,20,10;;
 }
 MeshTextureCoords {
  19;
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.862400;0.691600;,
  1.063400;0.514400;,
  0.529200;0.683600;,
  0.246800;0.692000;,
  -0.105800;0.514800;,
  0.514340;0.480520;,
  0.722400;0.115200;,
  0.487600;0.115200;,
  0.323200;0.113400;,
  0.458090;0.486780;,
  0.596330;0.486100;;
 }
}
