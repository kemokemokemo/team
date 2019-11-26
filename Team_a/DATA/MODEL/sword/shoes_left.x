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
 0.48226;-0.03514;-5.36655;,
 -3.53774;0.18486;3.01345;,
 3.08226;0.24486;3.45345;,
 -3.53774;-4.81514;4.73345;,
 3.70226;-4.79514;4.99345;,
 -5.09774;-4.83514;-12.34655;,
 6.50226;-4.95514;-11.76655;,
 1.06226;0.80486;-15.08656;,
 1.06226;-3.37514;-16.68656;,
 0.82226;-1.15514;-11.22655;;
 
 16;
 3;0,1,2;,
 3;2,1,3;,
 3;2,3,4;,
 3;5,3,1;,
 3;0,2,6;,
 3;5,1,0;,
 3;4,6,2;,
 3;7,8,5;,
 3;6,8,7;,
 3;5,8,6;,
 3;3,5,6;,
 3;3,6,4;,
 3;9,0,6;,
 3;9,6,7;,
 3;9,7,5;,
 3;9,5,0;;
 
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
  0.022961;0.985070;-0.170614;,
  0.258757;0.960025;-0.106754;,
  -0.234245;0.962385;-0.137636;,
  -0.050425;0.306428;0.950557;,
  -0.035162;0.288079;0.956961;,
  -0.821875;0.460611;-0.335199;,
  0.748421;0.656422;-0.094745;,
  -0.596252;0.286985;-0.749749;,
  0.559636;0.815698;0.146439;,
  -0.065657;0.324589;0.943573;,
  -0.995371;0.031261;0.090876;,
  -0.518094;0.853118;0.061390;,
  0.972442;0.168774;0.160849;,
  0.688168;0.259371;-0.677607;,
  -0.002383;-0.987646;-0.156683;,
  0.005745;-0.950227;-0.311507;,
  -0.000776;-0.994888;-0.100980;,
  -0.004023;-0.999974;0.006037;,
  0.002405;-0.999948;0.009948;,
  0.533965;0.740021;0.408962;,
  -0.537549;0.838965;0.084731;,
  -0.541159;0.762902;0.353733;;
  16;
  3;0,2,1;,
  3;3,9,3;,
  3;3,3,4;,
  3;5,10,10;,
  3;0,1,6;,
  3;11,2,0;,
  3;12,6,12;,
  3;7,7,5;,
  3;6,13,13;,
  3;14,15,16;,
  3;17,14,16;,
  3;17,16,18;,
  3;8,0,6;,
  3;8,6,19;,
  3;20,21,11;,
  3;20,5,0;;
 }
 MeshTextureCoords {
  10;
  0.391600;1.035600;,
  0.910200;0.969000;,
  0.940400;0.969400;,
  1.012700;0.491700;,
  1.035200;0.491300;,
  0.082000;0.483300;,
  0.121100;0.482400;,
  -0.208000;0.736400;,
  -0.308600;0.480000;,
  0.030620;0.855470;;
 }
}
