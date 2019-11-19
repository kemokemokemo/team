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
 -2.71341;0.23448;0.48000;,
 -1.25340;-13.92552;-2.54000;,
 -0.07340;-0.14552;-2.82000;,
 -2.71341;0.23448;0.48000;,
 -0.07340;-0.14552;-2.82000;,
 3.16659;-0.06552;2.58000;,
 -1.25340;-13.92552;-2.54000;,
 -2.71341;0.23448;0.48000;,
 -3.27341;-13.78552;0.62000;,
 -0.07340;-0.14552;-2.82000;,
 0.64660;-13.90552;1.44000;,
 3.16659;-0.06552;2.58000;,
 0.64660;-13.90552;1.44000;,
 -0.07340;-0.14552;-2.82000;,
 -1.25340;-13.92552;-2.54000;,
 -3.27341;-13.78552;0.62000;,
 3.16659;-0.06552;2.58000;,
 0.64660;-13.90552;1.44000;,
 3.16659;-0.06552;2.58000;,
 -3.27341;-13.78552;0.62000;,
 -2.71341;0.23448;0.48000;;
 
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
  -0.810468;0.041061;-0.584343;,
  -0.776710;0.053759;-0.627560;,
  0.071367;0.995787;-0.057572;,
  -0.841657;0.028233;-0.539273;,
  0.877043;-0.099608;-0.469972;,
  0.852716;-0.113258;-0.509950;,
  0.899286;-0.085722;-0.428877;,
  -0.271280;-0.010157;0.962447;,
  -0.205824;-0.043052;0.977642;,
  -0.335218;0.022795;0.941865;;
  7;
  3;1,0,0;,
  3;2,2,2;,
  3;3,0,0;,
  3;5,4,4;,
  3;6,4,4;,
  3;8,7,7;,
  3;9,7,7;;
 }
 MeshTextureCoords {
  21;
  0.516100;0.217300;,
  0.516100;0.217300;,
  0.516100;0.217300;,
  -0.562600;0.500500;,
  -0.562600;0.500500;,
  -0.562600;0.500500;,
  0.526500;0.312900;,
  0.526500;0.312900;,
  0.526500;0.312900;,
  0.531700;0.167600;,
  0.531700;0.167600;,
  0.531700;0.167600;,
  0.521300;0.247400;,
  0.521300;0.247400;,
  0.521300;0.247400;,
  0.531700;1.594900;,
  0.531700;1.594900;,
  0.531700;1.594900;,
  0.516100;1.535200;,
  0.516100;1.535200;,
  0.516100;1.535200;;
 }
}
