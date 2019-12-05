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
 38;
 8.30423;-2.04011;-6.14741;,
 1.94591;-3.70322;-0.08539;,
 9.67401;-1.04388;2.50768;,
 1.94591;-3.70322;-0.08539;,
 8.30423;-2.04011;-6.14741;,
 2.37618;-0.74064;-3.30539;,
 10.55928;6.12265;-0.76539;,
 2.37618;-0.74064;-3.30539;,
 8.30423;-2.04011;-6.14741;,
 2.37618;-0.74064;-3.30539;,
 -0.03812;0.05759;-0.08539;,
 1.94591;-3.70322;-0.08539;,
 2.37166;-0.41756;2.79461;,
 1.94591;-3.70322;-0.08539;,
 -0.03812;0.05759;-0.08539;,
 3.13031;3.23303;-0.60539;,
 13.65298;-1.55603;-3.70539;,
 8.30423;-2.04011;-6.14741;,
 9.67401;-1.04388;2.50768;,
 3.13031;3.23303;-0.60539;,
 -0.03812;0.05759;-0.08539;,
 2.37618;-0.74064;-3.30539;,
 2.37166;-0.41756;2.79461;,
 -0.03812;0.05759;-0.08539;,
 3.13031;3.23303;-0.60539;,
 13.65298;-1.55603;-3.70539;,
 10.55928;6.12265;-0.76539;,
 8.30423;-2.04011;-6.14741;,
 9.67401;-1.04388;2.50768;,
 1.94591;-3.70322;-0.08539;,
 2.37166;-0.41756;2.79461;,
 2.37166;-0.41756;2.79461;,
 10.55928;6.12265;-0.76539;,
 9.67401;-1.04388;2.50768;,
 3.13031;3.23303;-0.60539;,
 13.65298;-1.55603;-3.70539;,
 9.67401;-1.04388;2.50768;,
 10.55928;6.12265;-0.76539;;
 
 14;
 3;2,1,0;,
 3;5,4,3;,
 3;8,7,6;,
 3;11,10,9;,
 3;14,13,12;,
 3;7,15,6;,
 3;18,17,16;,
 3;21,20,19;,
 3;24,23,22;,
 3;27,26,25;,
 3;30,29,28;,
 3;33,32,31;,
 3;32,34,31;,
 3;37,36,35;;
 
 MeshMaterialList {
  7;
  14;
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
  20;
  0.175198;-0.980842;0.085171;,
  0.153442;-0.881444;0.446668;,
  0.115344;-0.936191;0.332028;,
  -0.624308;-0.531532;-0.572462;,
  -0.052072;0.558467;-0.827891;,
  -0.791057;0.062292;-0.608563;,
  -0.415304;-0.568599;0.710083;,
  -0.439118;0.560453;-0.702188;,
  0.040635;-0.993330;0.107905;,
  -0.443840;-0.629120;-0.638133;,
  -0.375345;0.569840;-0.731026;,
  0.047700;0.540612;-0.839919;,
  -0.737139;-0.388881;0.552628;,
  -0.253697;0.605569;0.754270;,
  -0.540781;0.630724;0.556546;,
  -0.401817;0.667428;0.626963;,
  0.336338;0.451863;-0.826254;,
  -0.093728;0.563944;0.820477;,
  0.509628;0.304560;0.804688;,
  0.839288;0.136662;0.526231;;
  14;
  3;2,1,0;,
  3;3,9,3;,
  3;11,10,4;,
  3;3,5,3;,
  3;12,12,6;,
  3;10,7,4;,
  3;2,0,8;,
  3;10,5,7;,
  3;15,14,13;,
  3;11,4,16;,
  3;6,1,2;,
  3;18,17,13;,
  3;17,15,13;,
  3;19,18,19;;
 }
 MeshTextureCoords {
  38;
  0.296700;0.682700;,
  0.296700;0.682700;,
  0.296700;0.682700;,
  0.024400;0.361700;,
  0.024400;0.361700;,
  0.024400;0.361700;,
  0.443000;0.093500;,
  0.443000;0.093500;,
  0.443000;0.093500;,
  0.101600;0.268200;,
  0.101600;0.268200;,
  0.101600;0.268200;,
  0.117900;0.812800;,
  0.117900;0.812800;,
  0.117900;0.812800;,
  0.443000;0.093500;,
  0.764000;0.593300;,
  0.764000;0.593300;,
  0.764000;0.593300;,
  0.252000;0.182900;,
  0.252000;0.182900;,
  0.252000;0.182900;,
  0.284500;0.800600;,
  0.284500;0.800600;,
  0.284500;0.800600;,
  0.690900;0.065000;,
  0.690900;0.065000;,
  0.690900;0.065000;,
  0.174700;0.853400;,
  0.174700;0.853400;,
  0.174700;0.853400;,
  0.483600;0.914400;,
  0.483600;0.914400;,
  0.483600;0.914400;,
  0.483600;0.914400;,
  0.967200;0.772100;,
  0.967200;0.772100;,
  0.967200;0.772100;;
 }
}
