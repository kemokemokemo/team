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
 -10.48139;1.73655;0.49495;,
 -2.92663;0.50730;-3.22718;,
 -2.08183;3.82156;1.75282;,
 -10.62011;0.29589;-2.58305;,
 -10.62011;0.29589;-2.58305;,
 -3.86883;-2.34293;2.91282;,
 -2.92663;0.50730;-3.22718;,
 -9.95920;-1.42006;1.06868;,
 -2.08183;3.82156;1.75282;,
 -3.86883;-2.34293;2.91282;,
 -9.95920;-1.42006;1.06868;,
 -10.48139;1.73655;0.49495;,
 -2.08183;3.82156;1.75282;,
 -0.07390;0.03371;-0.14718;,
 -3.86883;-2.34293;2.91282;,
 -2.92663;0.50730;-3.22718;,
 -0.07390;0.03371;-0.14718;,
 -2.08183;3.82156;1.75282;,
 -3.86883;-2.34293;2.91282;,
 -0.07390;0.03371;-0.14718;,
 -2.92663;0.50730;-3.22718;;
 
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
  -0.060113;0.905102;-0.420924;,
  -0.094002;0.872753;-0.479026;,
  -0.008859;-0.905639;-0.423956;,
  0.161428;0.836992;-0.522863;,
  0.278049;0.777241;-0.564433;,
  0.079629;-0.908492;-0.410246;,
  0.643151;-0.042571;0.764555;,
  -0.009657;-0.906007;-0.423153;,
  0.124043;-0.907164;-0.402078;,
  0.079451;0.130010;0.988324;,
  0.225635;0.116596;0.967210;,
  -0.214517;0.197540;0.956536;,
  -0.182001;0.146615;0.972306;,
  0.636570;0.587850;-0.499210;,
  0.256246;-0.891172;-0.374367;;
  9;
  3;4,3,1;,
  3;3,0,1;,
  3;8,5,7;,
  3;5,2,7;,
  3;11,10,9;,
  3;12,11,9;,
  3;10,6,9;,
  3;4,13,3;,
  3;8,14,5;;
 }
 MeshTextureCoords {
  21;
  0.398300;0.247900;,
  0.398300;0.247900;,
  0.398300;0.247900;,
  0.398300;0.247900;,
  0.532400;0.325100;,
  0.532400;0.325100;,
  0.532400;0.325100;,
  0.532400;0.325100;,
  0.438900;1.016000;,
  0.438900;1.016000;,
  0.438900;1.016000;,
  0.438900;1.016000;,
  0.199100;0.918500;,
  0.199100;0.918500;,
  0.199100;0.918500;,
  0.142200;0.247900;,
  0.142200;0.247900;,
  0.142200;0.247900;,
  0.479500;0.341400;,
  0.479500;0.341400;,
  0.479500;0.341400;;
 }
}
