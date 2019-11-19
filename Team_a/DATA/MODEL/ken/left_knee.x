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
 27;
 5.96782;-5.06772;5.90970;,
 -9.77379;-16.69276;2.06027;,
 -5.45471;-5.28543;1.39581;,
 -9.77379;-16.69276;2.06027;,
 5.96782;-5.06772;5.90970;,
 5.46154;-18.04248;9.51181;,
 4.30666;-4.61057;-7.55869;,
 -9.77379;-16.69276;2.06027;,
 3.30994;-18.04248;-8.87181;,
 -9.77379;-16.69276;2.06027;,
 4.30666;-4.61057;-7.55869;,
 -5.45471;-5.28543;1.39581;,
 4.30666;-4.61057;-7.55869;,
 5.46154;-18.04248;9.51181;,
 5.96782;-5.06772;5.90970;,
 -5.45471;-5.28543;1.39581;,
 0.00341;-0.03892;-0.26536;,
 5.96782;-5.06772;5.90970;,
 5.96782;-5.06772;5.90970;,
 0.00341;-0.03892;-0.26536;,
 4.30666;-4.61057;-7.55869;,
 5.46154;-18.04248;9.51181;,
 4.30666;-4.61057;-7.55869;,
 3.30994;-18.04248;-8.87181;,
 4.30666;-4.61057;-7.55869;,
 0.00341;-0.03892;-0.26536;,
 -5.45471;-5.28543;1.39581;;
 
 9;
 3;2,1,0;,
 3;5,4,3;,
 3;8,7,6;,
 3;11,10,9;,
 3;14,13,12;,
 3;17,16,15;,
 3;20,19,18;,
 3;23,22,21;,
 3;26,25,24;;
 
 MeshMaterialList {
  7;
  9;
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
  15;
  -0.366559;0.344373;0.864316;,
  -0.385183;0.225241;0.894930;,
  -0.345293;0.386702;0.855122;,
  -0.405724;0.259164;0.876482;,
  -0.646917;0.261671;-0.716259;,
  -0.628993;0.121737;-0.767820;,
  -0.312218;0.566319;0.762760;,
  -0.649821;0.166942;-0.741528;,
  -0.650426;0.329939;-0.684168;,
  0.969882;0.217731;-0.109185;,
  0.990429;-0.067702;-0.120277;,
  0.925180;0.365650;-0.101698;,
  0.678368;0.732365;-0.058810;,
  0.991296;-0.062217;-0.116020;,
  -0.622406;0.443261;-0.645082;;
  9;
  3;2,1,0;,
  3;3,0,1;,
  3;5,7,4;,
  3;8,4,7;,
  3;11,10,9;,
  3;0,6,2;,
  3;9,12,11;,
  3;13,9,10;,
  3;8,14,4;;
 }
 MeshTextureCoords {
  27;
  0.294600;0.638700;,
  0.294600;0.638700;,
  0.294600;0.638700;,
  0.318700;0.589800;,
  0.318700;0.589800;,
  0.318700;0.589800;,
  0.131200;0.573800;,
  0.131200;0.573800;,
  0.131200;0.573800;,
  0.092000;0.622400;,
  0.092000;0.622400;,
  0.092000;0.622400;,
  1.574700;0.495200;,
  1.574700;0.495200;,
  1.574700;0.495200;,
  0.375800;1.051300;,
  0.375800;1.051300;,
  0.375800;1.051300;,
  0.830900;1.226500;,
  0.830900;1.226500;,
  0.830900;1.226500;,
  1.574700;0.487200;,
  1.574700;0.487200;,
  1.574700;0.487200;,
  0.184800;0.830900;,
  0.184800;0.830900;,
  0.184800;0.830900;;
 }
}
