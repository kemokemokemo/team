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
 13;
 0.38120;0.03443;4.47905;,
 6.84120;-5.18557;1.13905;,
 0.22120;0.17443;-4.26095;,
 -1.37880;-12.34557;-3.72095;,
 3.70120;-20.48557;1.15905;,
 -5.63880;-0.98557;0.87905;,
 -1.39880;-12.34557;6.45905;,
 -7.03880;-15.14557;1.11905;,
 -3.61880;-30.94558;-3.44095;,
 -3.77880;-30.74558;5.37905;,
 0.44120;-30.82558;1.85905;,
 -3.65880;-34.84558;0.89905;,
 -7.81880;-30.84558;1.77905;;
 
 22;
 3;0,1,2;,
 3;1,3,2;,
 3;3,1,4;,
 3;0,2,5;,
 3;6,1,0;,
 3;7,2,3;,
 3;1,6,4;,
 3;2,7,5;,
 3;4,8,3;,
 3;7,0,5;,
 3;8,7,3;,
 3;0,7,6;,
 3;9,4,6;,
 3;8,4,10;,
 3;11,8,10;,
 3;9,10,4;,
 3;11,10,9;,
 3;7,8,12;,
 3;7,12,9;,
 3;11,12,8;,
 3;11,9,12;,
 3;7,9,6;;
 
 MeshMaterialList {
  8;
  22;
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5;;
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
    "C:\\Users\\game339\\Desktop\\���Ɛ���\\Team_a\\DATA\\TEX\\sword_face.png";
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
  30;
  0.247890;0.968726;0.010979;,
  0.628800;0.777566;0.000944;,
  0.590255;-0.104872;-0.800376;,
  0.661629;-0.164167;-0.731639;,
  -0.178070;0.983834;0.019019;,
  0.578386;-0.061527;0.813440;,
  -0.695692;0.046966;-0.716803;,
  0.701498;-0.317494;-0.638043;,
  0.596960;-0.314355;0.738119;,
  0.723282;-0.424789;-0.544443;,
  0.664289;-0.559010;-0.496213;,
  -0.748682;-0.288500;-0.596861;,
  0.577502;-0.114315;-0.808347;,
  0.574202;-0.108382;-0.811508;,
  0.560090;-0.029422;0.827909;,
  0.499967;0.066220;0.863509;,
  -0.664163;0.052864;-0.745716;,
  -0.665951;0.060981;-0.743499;,
  0.618836;-0.132471;0.774270;,
  -0.664399;0.053054;-0.745493;,
  -0.657516;0.097758;0.747072;,
  -0.630681;0.139295;0.763438;,
  -0.520320;0.065875;0.851427;,
  -0.733880;-0.168430;-0.658066;,
  -0.714866;0.129376;0.687189;,
  0.580242;-0.407959;0.704903;,
  -0.007428;-0.737779;0.675001;,
  -0.627386;-0.313587;0.712777;,
  -0.662956;-0.189684;0.724230;,
  -0.649296;-0.562706;-0.511641;;
  22;
  3;0,1,0;,
  3;12,2,13;,
  3;2,12,3;,
  3;0,0,4;,
  3;5,14,15;,
  3;6,16,17;,
  3;14,5,18;,
  3;16,6,19;,
  3;3,7,2;,
  3;20,21,22;,
  3;23,6,17;,
  3;21,20,24;,
  3;8,18,5;,
  3;7,3,9;,
  3;10,7,9;,
  3;8,25,18;,
  3;26,25,8;,
  3;6,23,11;,
  3;20,27,28;,
  3;29,11,23;,
  3;26,28,27;,
  3;20,28,24;;
 }
 MeshTextureCoords {
  13;
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;;
 }
}
