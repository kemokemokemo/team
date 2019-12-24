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
 3.88044;-2.34626;3.24000;,
 10.55340;0.50154;-2.20172;,
 2.87108;0.44501;-2.92000;,
 9.90270;-1.27357;1.62172;,
 2.87108;0.44501;-2.92000;,
 10.34227;1.97609;0.95401;,
 1.87939;3.75212;2.04000;,
 10.55340;0.50154;-2.20172;,
 3.88044;-2.34626;3.24000;,
 1.87939;3.75212;2.04000;,
 10.34227;1.97609;0.95401;,
 9.90270;-1.27357;1.62172;,
 0.01705;-0.08764;-0.06000;,
 1.87939;3.75212;2.04000;,
 3.88044;-2.34626;3.24000;,
 0.01705;-0.08764;-0.06000;,
 3.88044;-2.34626;3.24000;,
 2.87108;0.44501;-2.92000;,
 0.01705;-0.08764;-0.06000;,
 2.87108;0.44501;-2.92000;,
 1.87939;3.75212;2.04000;;
 
 9;
 3;2,1,0;,
 3;1,3,0;,
 3;6,5,4;,
 3;5,7,4;,
 3;10,9,8;,
 3;11,10,8;,
 3;14,13,12;,
 3;17,16,15;,
 3;20,19,18;;
 
 MeshMaterialList {
  7;
  9;
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
  15;
  0.048323;-0.908092;-0.415973;,
  0.050839;-0.909118;-0.413424;,
  0.069956;0.874240;-0.480428;,
  -0.037239;-0.913353;-0.405462;,
  -0.081536;-0.912774;-0.400244;,
  -0.281485;0.771447;-0.570646;,
  -0.672933;-0.076025;0.735786;,
  -0.173777;0.832191;-0.526555;,
  0.032722;0.906329;-0.421303;,
  -0.100974;0.124801;0.987030;,
  -0.282027;0.095311;0.954660;,
  0.201200;0.205719;0.957705;,
  0.228174;0.166249;0.959322;,
  -0.207525;-0.903360;-0.375333;,
  -0.625781;0.585417;-0.515447;;
  9;
  3;4,0,3;,
  3;0,1,3;,
  3;5,2,7;,
  3;2,8,7;,
  3;11,10,9;,
  3;12,11,9;,
  3;9,10,6;,
  3;4,3,13;,
  3;5,7,14;;
 }
 MeshTextureCoords {
  21;
  0.532400;0.325100;,
  0.532400;0.325100;,
  0.532400;0.325100;,
  0.532400;0.325100;,
  0.398300;0.243800;,
  0.398300;0.243800;,
  0.398300;0.243800;,
  0.398300;0.243800;,
  0.434800;1.016000;,
  0.434800;1.016000;,
  0.434800;1.016000;,
  0.434800;1.016000;,
  0.195100;0.914400;,
  0.195100;0.914400;,
  0.195100;0.914400;,
  0.479500;0.341400;,
  0.479500;0.341400;,
  0.479500;0.341400;,
  0.146300;0.243800;,
  0.146300;0.243800;,
  0.146300;0.243800;;
 }
}
