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
 -6.16967;-17.24753;10.91900;,
 -4.87613;-4.27646;-7.94213;,
 -6.53675;-4.71794;6.81488;,
 -6.53675;-4.71794;6.81488;,
 10.68124;-15.94412;2.68583;,
 -6.16967;-17.24753;10.91900;,
 10.68124;-15.94412;2.68583;,
 -6.53675;-4.71794;6.81488;,
 5.90914;-5.15942;1.95166;,
 -4.87613;-4.27646;-7.94213;,
 -6.16967;-17.24753;10.91900;,
 -3.60007;-17.47879;-9.39299;,
 -6.53675;-4.71794;6.81488;,
 -0.12152;0.13833;0.11624;,
 5.90914;-5.15942;1.95166;,
 -0.12152;0.13833;0.11624;,
 -6.53675;-4.71794;6.81488;,
 -4.87613;-4.27646;-7.94213;,
 -4.87613;-4.27646;-7.94213;,
 10.68124;-15.94412;2.68583;,
 5.90914;-5.15942;1.95166;,
 10.68124;-15.94412;2.68583;,
 -4.87613;-4.27646;-7.94213;,
 -3.60007;-17.47879;-9.39299;,
 -0.12152;0.13833;0.11624;,
 -4.87613;-4.27646;-7.94213;,
 5.90914;-5.15942;1.95166;;
 
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
    "C:\\Users\\game339\\Desktop\\���Ɛ���\\team_Prototype\\DATA\\TEX\\IMG_2227.JPG";
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
  -0.990144;-0.074086;-0.118856;,
  -0.967281;0.230588;-0.105811;,
  -0.913602;0.396307;-0.090952;,
  0.381652;0.259008;0.887275;,
  0.342759;0.423040;0.838781;,
  -0.988873;-0.081934;-0.124166;,
  0.308265;0.605197;0.733968;,
  0.363227;0.380835;0.850312;,
  0.400786;0.295769;0.867117;,
  -0.634438;0.771463;-0.048314;,
  0.644080;0.294516;-0.705990;,
  0.649158;0.196126;-0.734935;,
  0.644935;0.367124;-0.670283;,
  0.629861;0.144739;-0.763103;,
  0.613526;0.481583;-0.625830;;
  9;
  3;2,1,0;,
  3;8,3,7;,
  3;4,7,3;,
  3;5,0,1;,
  3;4,6,7;,
  3;1,2,9;,
  3;12,11,10;,
  3;13,10,11;,
  3;12,10,14;;
 }
 MeshTextureCoords {
  27;
  -0.542500;0.495200;,
  -0.542500;0.495200;,
  -0.542500;0.495200;,
  0.713500;0.589800;,
  0.713500;0.589800;,
  0.713500;0.589800;,
  0.737600;0.638700;,
  0.737600;0.638700;,
  0.737600;0.638700;,
  -0.542500;0.487200;,
  -0.542500;0.487200;,
  -0.542500;0.487200;,
  0.656500;1.051300;,
  0.656500;1.051300;,
  0.656500;1.051300;,
  0.201400;1.226500;,
  0.201400;1.226500;,
  0.201400;1.226500;,
  0.940300;0.622400;,
  0.940300;0.622400;,
  0.940300;0.622400;,
  0.901100;0.573800;,
  0.901100;0.573800;,
  0.901100;0.573800;,
  0.847500;0.830900;,
  0.847500;0.830900;,
  0.847500;0.830900;;
 }
}