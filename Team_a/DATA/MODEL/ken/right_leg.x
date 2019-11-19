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
 21;
 -0.26168;-14.06309;1.52000;,
 0.21832;-0.22309;-2.64000;,
 -2.78168;-0.22309;2.74000;,
 2.93833;0.07691;1.28000;,
 -2.78168;-0.22309;2.74000;,
 0.21832;-0.22309;-2.64000;,
 0.21832;-0.22309;-2.64000;,
 -0.26168;-14.06309;1.52000;,
 1.59832;-13.98309;-2.70000;,
 1.59832;-13.98309;-2.70000;,
 2.93833;0.07691;1.28000;,
 0.21832;-0.22309;-2.64000;,
 2.93833;0.07691;1.28000;,
 1.59832;-13.98309;-2.70000;,
 3.63832;-13.92309;0.66000;,
 -2.78168;-0.22309;2.74000;,
 3.63832;-13.92309;0.66000;,
 -0.26168;-14.06309;1.52000;,
 3.63832;-13.92309;0.66000;,
 -2.78168;-0.22309;2.74000;,
 2.93833;0.07691;1.28000;;
 
 7;
 3;2,1,0;,
 3;5,4,3;,
 3;8,7,6;,
 3;11,10,9;,
 3;14,13,12;,
 3;17,16,15;,
 3;20,19,18;;
 
 MeshMaterialList {
  7;
  7;
  5,
  5,
  5,
  5,
  5,
  5,
  5;;
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
  10;
  -0.890163;-0.102568;-0.443947;,
  -0.867563;-0.115322;-0.483771;,
  -0.061002;0.997558;-0.034016;,
  -0.910752;-0.089582;-0.403120;,
  0.852427;0.065593;-0.518716;,
  0.834507;0.074987;-0.545871;,
  0.815630;0.084296;-0.572400;,
  0.232737;-0.038476;0.971778;,
  0.216698;-0.046501;0.975131;,
  0.248699;-0.030438;0.968102;;
  7;
  3;1,0,0;,
  3;2,2,2;,
  3;3,0,0;,
  3;6,5,5;,
  3;4,5,5;,
  3;8,7,7;,
  3;9,7,7;;
 }
 MeshTextureCoords {
  21;
  0.534400;0.167600;,
  0.534400;0.167600;,
  0.534400;0.167600;,
  -0.562600;0.495200;,
  -0.562600;0.495200;,
  -0.562600;0.495200;,
  0.523900;0.254500;,
  0.523900;0.254500;,
  0.523900;0.254500;,
  0.518700;0.281800;,
  0.518700;0.281800;,
  0.518700;0.281800;,
  0.521300;0.312900;,
  0.521300;0.312900;,
  0.521300;0.312900;,
  0.526500;1.594900;,
  0.526500;1.594900;,
  0.526500;1.594900;,
  0.521300;1.574700;,
  0.521300;1.574700;,
  0.521300;1.574700;;
 }
}
