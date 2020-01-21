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
 -5.21924;-4.54768;-6.58679;,
 -5.71970;0.12740;-2.72956;,
 -5.58543;-0.89795;9.42809;,
 -5.74412;-4.57209;10.05061;,
 -5.21924;-4.54768;-6.58679;,
 1.73845;3.64286;-6.04972;,
 -5.71970;0.12740;-2.72956;,
 5.15625;0.12740;1.39623;,
 -5.58543;-0.89795;9.42809;,
 -5.71970;0.12740;-2.72956;,
 -5.58543;-0.89795;9.42809;,
 5.15625;0.12740;1.39623;,
 10.39283;-4.53547;-0.92300;,
 -5.74412;-4.57209;10.05061;,
 10.39283;-4.53547;-0.92300;,
 -5.21924;-4.54768;-6.58679;,
 -5.74412;-4.57209;10.05061;,
 -5.71970;0.12740;-2.72956;,
 1.73845;3.64286;-6.04972;,
 5.15625;0.12740;1.39623;,
 10.39283;-4.53547;-0.92300;,
 1.73845;3.64286;-6.04972;,
 4.47269;-4.42561;-9.88253;,
 1.73845;3.64286;-6.04972;,
 10.39283;-4.53547;-0.92300;,
 5.15625;0.12740;1.39623;,
 -5.21924;-4.54768;-6.58679;,
 10.39283;-4.53547;-0.92300;,
 4.47269;-4.42561;-9.88253;,
 1.73845;3.64286;-6.04972;,
 -5.21924;-4.54768;-6.58679;,
 4.47269;-4.42561;-9.88253;;
 
 12;
 3;2,1,0;,
 3;3,2,0;,
 3;6,5,4;,
 3;9,8,7;,
 3;12,11,10;,
 3;13,12,10;,
 3;16,15,14;,
 3;19,18,17;,
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
  19;
  -0.848581;0.224768;-0.478946;,
  -0.994152;-0.107970;0.001874;,
  -0.999271;-0.035180;-0.014832;,
  -0.998790;0.037808;-0.031454;,
  -0.430476;0.418133;-0.799909;,
  0.169467;0.959147;0.226535;,
  0.672410;0.409938;0.616292;,
  0.735744;0.477488;-0.480298;,
  -0.537999;0.501449;-0.677574;,
  -0.031997;0.995923;0.084347;,
  -0.111423;0.949375;0.293722;,
  0.563344;0.179725;0.806438;,
  0.565780;0.243574;0.787759;,
  0.558413;0.115080;0.821543;,
  0.004089;-0.999950;-0.009116;,
  0.001299;-0.999998;-0.001426;,
  0.280151;0.911323;0.301671;,
  0.006878;-0.999835;-0.016804;,
  -0.308546;0.320822;-0.895473;;
  12;
  3;2,1,0;,
  3;3,2,0;,
  3;8,4,0;,
  3;10,9,5;,
  3;6,12,11;,
  3;13,6,11;,
  3;15,14,14;,
  3;5,16,10;,
  3;7,7,7;,
  3;5,6,16;,
  3;17,14,14;,
  3;18,0,4;;
 }
 MeshTextureCoords {
  32;
  0.341400;0.516100;,
  0.341400;0.516100;,
  0.341400;0.516100;,
  0.341400;0.516100;,
  0.723400;0.219500;,
  0.723400;0.219500;,
  0.723400;0.219500;,
  0.434800;0.004100;,
  0.434800;0.004100;,
  0.434800;0.004100;,
  0.223500;0.471400;,
  0.223500;0.471400;,
  0.223500;0.471400;,
  0.223500;0.471400;,
  0.548600;1.032200;,
  0.548600;1.032200;,
  0.548600;1.032200;,
  0.215400;0.093500;,
  0.215400;0.093500;,
  0.215400;0.093500;,
  0.865600;0.260100;,
  0.865600;0.260100;,
  0.865600;0.260100;,
  0.593300;0.146300;,
  0.593300;0.146300;,
  0.593300;0.146300;,
  0.560800;1.032200;,
  0.560800;1.032200;,
  0.560800;1.032200;,
  0.877800;0.308900;,
  0.877800;0.308900;,
  0.877800;0.308900;;
 }
}
