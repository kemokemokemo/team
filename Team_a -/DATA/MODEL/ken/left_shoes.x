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
 32;
 -11.08864;-4.45573;-2.79934;,
 4.95065;-0.76938;7.74704;,
 5.20699;-4.33367;8.29633;,
 -6.04738;0.25596;0.19124;,
 -11.08864;-4.45573;-2.79934;,
 -2.83706;3.79583;-7.47442;,
 -6.04738;0.25596;0.19124;,
 4.95065;-0.76938;7.74704;,
 -6.04738;0.25596;0.19124;,
 4.65769;0.28038;-4.11764;,
 4.95065;-0.76938;7.74704;,
 4.47460;-4.50456;-8.41431;,
 5.20699;-4.33367;8.29633;,
 -6.04738;0.25596;0.19124;,
 -2.83706;3.79583;-7.47442;,
 4.65769;0.28038;-4.11764;,
 4.47460;-4.50456;-8.41431;,
 -11.08864;-4.45573;-2.79934;,
 5.20699;-4.33367;8.29633;,
 4.65769;0.28038;-4.11764;,
 -2.83706;3.79583;-7.47442;,
 4.47460;-4.50456;-8.41431;,
 4.65769;0.28038;-4.11764;,
 -2.83706;3.79583;-7.47442;,
 -11.08864;-4.45573;-2.79934;,
 -5.16850;-4.30925;-11.75888;,
 -11.08864;-4.45573;-2.79934;,
 4.47460;-4.50456;-8.41431;,
 -5.16850;-4.30925;-11.75888;,
 4.47460;-4.50456;-8.41431;,
 -2.83706;3.79583;-7.47442;,
 -5.16850;-4.30925;-11.75888;;
 
 12;
 3;2,1,0;,
 3;1,3,0;,
 3;6,5,4;,
 3;9,8,7;,
 3;12,11,10;,
 3;15,14,13;,
 3;18,17,16;,
 3;11,19,10;,
 3;22,21,20;,
 3;25,24,23;,
 3;28,27,26;,
 3;31,30,29;;
 
 MeshMaterialList {
  7;
  12;
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
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
     "Tex_kan_eye.jpg";
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
    "Tex_kan_eye.jpg";
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
  18;
  -0.560520;0.080900;0.824180;,
  -0.561151;0.086501;0.823181;,
  -0.559871;0.075296;0.825151;,
  -0.750271;0.619588;-0.230659;,
  0.114050;0.950592;0.288733;,
  0.838040;0.285987;-0.464650;,
  -0.740875;0.467849;-0.481894;,
  -0.176029;0.958344;0.224925;,
  0.032860;0.995642;0.087280;,
  0.999067;0.025001;-0.035206;,
  0.996908;0.064861;-0.044355;,
  0.189627;0.858769;0.475979;,
  -0.005659;-0.999960;-0.006990;,
  0.000544;-0.999948;0.010202;,
  0.875631;0.303712;-0.375538;,
  0.434379;0.469668;-0.768588;,
  -0.011860;-0.999637;-0.024179;,
  0.310796;0.372779;-0.874324;;
  12;
  3;1,0,0;,
  3;0,2,0;,
  3;7,3,3;,
  3;4,7,8;,
  3;10,5,9;,
  3;4,11,7;,
  3;13,12,12;,
  3;5,14,9;,
  3;14,5,15;,
  3;6,3,3;,
  3;16,12,12;,
  3;17,15,5;;
 }
 MeshTextureCoords {
  32;
  0.227600;0.536400;,
  0.227600;0.536400;,
  0.227600;0.536400;,
  0.227600;0.536400;,
  0.609600;0.170700;,
  0.609600;0.170700;,
  0.609600;0.170700;,
  0.434800;0.008100;,
  0.434800;0.008100;,
  0.434800;0.008100;,
  0.337300;0.471400;,
  0.337300;0.471400;,
  0.337300;0.471400;,
  0.227600;0.089400;,
  0.227600;0.089400;,
  0.227600;0.089400;,
  0.544600;1.032200;,
  0.544600;1.032200;,
  0.544600;1.032200;,
  0.337300;0.471400;,
  0.682700;0.178800;,
  0.682700;0.178800;,
  0.682700;0.178800;,
  0.873700;0.276300;,
  0.873700;0.276300;,
  0.873700;0.276300;,
  0.560800;1.028200;,
  0.560800;1.028200;,
  0.560800;1.028200;,
  0.861600;0.272300;,
  0.861600;0.272300;,
  0.861600;0.272300;;
 }
}
