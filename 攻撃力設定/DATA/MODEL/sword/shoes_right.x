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
 10;
 0.18035;-0.03691;-4.98083;,
 -2.41965;0.24309;3.13357;,
 4.20035;0.18309;2.69357;,
 4.20035;-4.81691;5.11917;,
 -3.03965;-4.79691;5.37917;,
 5.76035;-4.83691;-11.96083;,
 -5.83965;-4.95691;-11.38083;,
 -0.39965;0.80309;-14.70083;,
 -0.39965;-3.37691;-16.30083;,
 -0.15965;-1.15691;-10.84083;;
 
 16;
 3;0,1,2;,
 3;1,3,2;,
 3;1,4,3;,
 3;5,2,3;,
 3;0,6,1;,
 3;5,0,2;,
 3;4,1,6;,
 3;7,5,8;,
 3;6,7,8;,
 3;5,6,8;,
 3;3,6,5;,
 3;3,4,6;,
 3;9,6,0;,
 3;9,7,6;,
 3;9,5,7;,
 3;9,0,5;;
 
 MeshMaterialList {
  8;
  16;
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
   0.414118;0.225882;0.000000;1.000000;;
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
   0.332549;0.000000;0.037647;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.247843;0.006275;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.062745;0.062745;0.062745;1.000000;;
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
    "C:\\Users\\game339\\Desktop\\ë≤ã∆êßçÏ\\Team_a\\DATA\\TEX\\sword_face.png";
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
  22;
  -0.023965;0.983984;-0.176639;,
  -0.253277;0.960617;-0.114302;,
  0.226290;0.963035;-0.146142;,
  0.048804;0.419541;0.906424;,
  0.033953;0.403263;0.914454;,
  0.819893;0.464642;-0.334491;,
  -0.743936;0.661089;-0.097578;,
  0.596251;0.286985;-0.749749;,
  -0.559636;0.815698;0.146439;,
  0.063627;0.435587;0.897895;,
  0.994893;0.044057;0.090817;,
  0.511828;0.857382;0.054116;,
  -0.968574;0.190437;0.159996;,
  -0.688168;0.259371;-0.677607;,
  0.002383;-0.987646;-0.156683;,
  0.000776;-0.994888;-0.100980;,
  -0.005745;-0.950227;-0.311507;,
  0.004023;-0.999974;0.006037;,
  -0.002405;-0.999948;0.009948;,
  -0.533965;0.740021;0.408962;,
  0.537549;0.838965;0.084731;,
  0.541159;0.762902;0.353733;;
  16;
  3;0,1,2;,
  3;3,3,9;,
  3;3,4,3;,
  3;5,10,10;,
  3;0,6,1;,
  3;11,0,2;,
  3;12,12,6;,
  3;7,5,7;,
  3;6,13,13;,
  3;14,15,16;,
  3;17,15,14;,
  3;17,18,15;,
  3;8,6,0;,
  3;8,19,6;,
  3;20,11,21;,
  3;20,0,5;;
 }
 MeshTextureCoords {
  10;
  0.391600;1.035600;,
  0.940400;0.969400;,
  0.910200;0.969000;,
  1.012700;0.491700;,
  1.035200;0.491300;,
  0.082000;0.483300;,
  0.121100;0.482400;,
  -0.208000;0.736400;,
  -0.308600;0.480000;,
  0.030620;0.855470;;
 }
}
