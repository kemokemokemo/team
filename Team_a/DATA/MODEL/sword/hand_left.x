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
 -0.80000;-0.32000;3.38000;,
 -3.98000;-5.24000;-5.56000;,
 -1.96000;-5.28000;5.58000;,
 -2.16000;-0.36000;-2.96000;,
 -1.64000;-10.42000;-4.64000;,
 3.02000;-4.54000;-5.36000;,
 3.54000;-9.38000;-4.04000;,
 -1.96000;-5.28000;5.58000;,
 -1.64000;-10.42000;-4.64000;,
 -0.38000;-10.42000;4.64000;,
 -3.98000;-5.24000;-5.56000;,
 3.54000;-9.38000;-4.04000;,
 3.44000;-9.28000;3.78000;,
 -2.16000;-0.36000;-2.96000;,
 3.48000;0.10000;0.04000;,
 3.02000;-4.54000;-5.36000;,
 -3.98000;-5.24000;-5.56000;,
 4.94000;-6.52000;-2.32000;,
 -0.80000;-0.32000;3.38000;,
 -1.96000;-5.28000;5.58000;,
 5.02000;-6.54000;3.04000;,
 3.44000;-9.28000;3.78000;,
 -0.38000;-10.42000;4.64000;,
 3.54000;-9.38000;-4.04000;;
 
 19;
 3;0,1,2;,
 3;0,3,1;,
 3;4,5,6;,
 3;4,1,5;,
 3;7,8,9;,
 3;7,10,8;,
 3;9,11,12;,
 3;9,8,11;,
 3;13,14,15;,
 3;15,16,13;,
 3;15,14,17;,
 3;18,19,20;,
 3;20,14,18;,
 3;19,21,20;,
 3;20,17,14;,
 3;19,22,21;,
 3;17,21,23;,
 3;17,23,15;,
 3;17,20,21;;
 
 MeshMaterialList {
  78;
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
  -0.944282;0.271052;0.186716;,
  -0.976867;-0.139579;0.162017;,
  -0.980533;0.056086;0.188173;,
  -0.948017;0.246043;0.201808;,
  0.102025;-0.200175;-0.974434;,
  0.535784;-0.168105;-0.827452;,
  0.434261;0.209741;-0.876029;,
  -0.941218;-0.312695;0.127795;,
  0.731679;-0.681618;0.006546;,
  0.799676;0.469207;-0.374650;,
  0.973693;-0.104528;-0.202474;,
  0.423789;0.272759;0.863716;,
  0.011194;0.169615;-0.985447;,
  -0.926242;-0.347586;0.145811;,
  0.244824;-0.969551;-0.005602;,
  0.501697;-0.865041;0.002166;,
  0.199791;-0.979463;-0.027127;,
  0.132979;0.612281;-0.779377;,
  0.451602;0.378393;0.808006;,
  0.328675;0.085487;0.940566;,
  0.521997;0.448779;0.725339;,
  0.299572;-0.024766;0.953752;,
  0.988304;-0.151728;-0.015317;,
  0.246935;-0.100357;0.963821;;
  19;
  3;0,2,1;,
  3;0,3,2;,
  3;4,6,5;,
  3;4,12,6;,
  3;1,13,7;,
  3;1,2,13;,
  3;14,15,8;,
  3;14,16,15;,
  3;17,9,6;,
  3;6,12,17;,
  3;6,9,10;,
  3;18,19,11;,
  3;11,20,18;,
  3;19,21,11;,
  3;22,10,9;,
  3;19,23,21;,
  3;10,8,15;,
  3;10,5,6;,
  3;10,22,8;;
 }
 MeshTextureCoords {
  24;
  0.729700;0.845700;,
  1.045000;0.531300;,
  0.868400;0.517600;,
  0.846100;0.855500;,
  0.915000;0.160200;,
  0.491100;0.518600;,
  0.500800;0.183600;,
  -0.119500;0.085900;,
  1.069200;0.656300;,
  -0.016400;0.722700;,
  1.174300;-0.011700;,
  1.005500;0.777300;,
  0.084700;0.781300;,
  0.266300;-0.008900;,
  0.460900;0.002800;,
  0.000000;-0.410300;,
  0.064100;-0.437600;,
  0.247800;-0.591900;,
  0.792400;-0.006000;,
  1.000000;-0.428800;,
  0.707600;-0.582100;,
  0.806500;-0.820400;,
  0.919600;-0.887800;,
  0.123900;-0.832100;;
 }
}
