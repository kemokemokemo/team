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
 58;
 0.42172;-1.06407;7.13162;,
 0.42172;-8.93111;5.31601;,
 -5.66645;-8.93111;-0.47206;,
 0.42172;-11.18472;-0.47206;,
 -5.66645;-8.93111;-0.47206;,
 0.42172;-8.93111;5.31601;,
 0.42172;-11.18472;-0.47206;,
 0.42172;-8.93111;-7.90446;,
 -5.66645;-8.93111;-0.47206;,
 -9.72244;-0.90427;-0.29552;,
 -8.79827;10.74231;0.00000;,
 0.42172;10.74231;5.20156;,
 0.42172;-1.06407;7.13162;,
 -9.72244;-0.90427;-0.29552;,
 -5.66645;-8.93111;-0.47206;,
 0.42172;-8.93111;-7.90446;,
 0.42172;-0.90427;-9.09860;,
 -9.72244;-0.90427;-0.29552;,
 0.42172;-0.90427;-9.09860;,
 -8.79827;10.74231;0.00000;,
 -9.72244;-0.90427;-0.29552;,
 0.42172;-11.18472;-0.47206;,
 6.50988;-8.93111;-0.47206;,
 0.42172;-8.93111;-7.90446;,
 6.50988;-8.93111;-0.47206;,
 10.56589;-0.90427;-0.29552;,
 0.42172;-0.90427;-9.09860;,
 0.42172;-8.93111;-7.90446;,
 0.42172;13.15155;0.00000;,
 0.42172;10.74231;5.20156;,
 -8.79827;10.74231;0.00000;,
 0.42172;10.74231;5.20156;,
 9.64172;10.74231;0.00000;,
 10.56589;-0.90427;-0.29552;,
 -8.79827;10.74231;0.00000;,
 0.42172;-0.90427;-9.09860;,
 0.42172;10.74231;-6.45408;,
 0.42172;13.15155;0.00000;,
 9.64172;10.74231;0.00000;,
 0.42172;10.74231;5.20156;,
 0.42172;-1.06407;7.13162;,
 0.42172;-0.90427;-9.09860;,
 10.56589;-0.90427;-0.29552;,
 9.64172;10.74231;0.00000;,
 0.42172;13.15155;0.00000;,
 -8.79827;10.74231;0.00000;,
 0.42172;10.74231;-6.45408;,
 0.42172;13.15155;0.00000;,
 0.42172;10.74231;-6.45408;,
 9.64172;10.74231;0.00000;,
 0.42172;10.74231;-6.45408;,
 10.56589;-0.90427;-0.29552;,
 0.42172;-8.93111;5.31601;,
 0.42172;-1.06407;7.13162;,
 0.42172;-11.18472;-0.47206;,
 0.42172;-8.93111;5.31601;,
 6.50988;-8.93111;-0.47206;,
 6.50988;-8.93111;-0.47206;;
 
 24;
 3;2,1,0;,
 3;5,4,3;,
 3;8,7,6;,
 3;9,2,0;,
 3;12,11,10;,
 3;13,12,10;,
 3;16,15,14;,
 3;17,16,14;,
 3;20,19,18;,
 3;23,22,21;,
 3;26,25,24;,
 3;27,26,24;,
 3;30,29,28;,
 3;33,32,31;,
 3;36,35,34;,
 3;39,38,37;,
 3;40,33,31;,
 3;43,42,41;,
 3;46,45,44;,
 3;49,48,47;,
 3;50,43,41;,
 3;53,52,51;,
 3;56,55,54;,
 3;52,57,51;;
 
 MeshMaterialList {
  7;
  24;
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "DATA\\TEX\\boy_face.png";
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
  27;
  -0.591617;-0.076565;0.802575;,
  -0.274330;-0.777810;0.565469;,
  -0.571899;-0.675492;0.465449;,
  0.000000;-0.999242;0.038937;,
  -0.634409;-0.572249;-0.519669;,
  -0.586348;-0.140225;0.797830;,
  -0.489626;0.393307;0.778188;,
  -0.187999;0.736910;0.649323;,
  -0.667667;-0.035788;-0.743599;,
  0.639595;-0.479330;-0.600967;,
  0.650948;-0.116595;-0.750115;,
  -0.000000;0.999255;0.038600;,
  0.491290;0.016888;0.870832;,
  -0.220565;0.783543;-0.580871;,
  -0.704023;-0.198752;-0.681798;,
  -0.650948;-0.116595;-0.750115;,
  -0.547078;0.437505;-0.713649;,
  0.634409;-0.572249;-0.519669;,
  0.667667;-0.035788;-0.743599;,
  0.539598;0.074154;0.838651;,
  0.588561;-0.096253;0.802702;,
  0.252641;0.966839;0.037348;,
  0.590813;-0.026241;0.806382;,
  0.610562;0.127308;-0.781669;,
  0.563796;0.182880;-0.805413;,
  0.618300;-0.263831;0.740337;,
  0.520952;-0.654481;0.547963;;
  24;
  3;2,1,0;,
  3;1,2,3;,
  3;2,4,3;,
  3;5,2,0;,
  3;0,7,6;,
  3;5,0,6;,
  3;8,4,14;,
  3;15,8,14;,
  3;15,16,8;,
  3;17,9,3;,
  3;18,10,9;,
  3;17,18,9;,
  3;6,7,11;,
  3;20,12,19;,
  3;13,8,16;,
  3;7,21,11;,
  3;22,20,19;,
  3;23,10,18;,
  3;13,16,11;,
  3;21,13,11;,
  3;24,23,18;,
  3;22,25,20;,
  3;26,1,3;,
  3;25,26,20;;
 }
 MeshTextureCoords {
  58;
  0.211300;0.394200;,
  0.211300;0.394200;,
  0.211300;0.394200;,
  0.345400;0.085300;,
  0.345400;0.085300;,
  0.345400;0.085300;,
  0.337300;0.065000;,
  0.337300;0.065000;,
  0.337300;0.065000;,
  0.211300;0.394200;,
  0.186900;0.621800;,
  0.186900;0.621800;,
  0.186900;0.621800;,
  0.186900;0.621800;,
  0.166600;0.386100;,
  0.166600;0.386100;,
  0.166600;0.386100;,
  0.166600;0.386100;,
  0.170700;0.666500;,
  0.170700;0.666500;,
  0.170700;0.666500;,
  0.694900;0.065000;,
  0.694900;0.065000;,
  0.694900;0.065000;,
  0.865600;0.386100;,
  0.865600;0.386100;,
  0.865600;0.386100;,
  0.865600;0.386100;,
  0.312900;0.946900;,
  0.312900;0.946900;,
  0.312900;0.946900;,
  0.845300;0.621800;,
  0.845300;0.621800;,
  0.845300;0.621800;,
  0.166600;0.658400;,
  0.166600;0.658400;,
  0.166600;0.658400;,
  0.719300;0.946900;,
  0.719300;0.946900;,
  0.719300;0.946900;,
  0.845300;0.621800;,
  0.865600;0.662400;,
  0.865600;0.662400;,
  0.865600;0.662400;,
  0.312900;0.942800;,
  0.312900;0.942800;,
  0.312900;0.942800;,
  0.719300;0.942800;,
  0.719300;0.942800;,
  0.719300;0.942800;,
  0.865600;0.662400;,
  0.820900;0.394200;,
  0.820900;0.394200;,
  0.820900;0.394200;,
  0.686800;0.085300;,
  0.686800;0.085300;,
  0.686800;0.085300;,
  0.820900;0.394200;;
 }
}
