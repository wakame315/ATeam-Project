<<<<<<< HEAD
=======
<<<<<<< HEAD
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
 55;
 -32.57848;-7.55490;7.47456;,
 -32.56897;-10.60060;0.03106;,
 -4.02749;-9.93860;0.03006;,
 -4.02749;-7.10390;7.03236;,
 -32.57848;-7.55490;-7.41243;,
 -4.02749;-7.10390;-6.97223;,
 -0.16539;-4.61680;4.95056;,
 -0.16539;-5.28070;0.17286;,
 -0.16539;0.01080;0.03007;,
 -0.16539;-0.07750;5.87696;,
 -0.16539;-4.72460;-4.60494;,
 -0.16539;-0.08010;-5.24174;,
 -0.16539;4.96600;0.17526;,
 -0.16539;4.46180;5.02057;,
 -0.16539;4.56440;-4.66994;,
 -4.02749;7.12570;7.03236;,
 -4.02749;9.23010;0.03006;,
 -32.34917;10.53570;0.03106;,
 -32.57848;7.57130;7.47456;,
 -4.02749;7.12570;-6.97223;,
 -32.57848;7.57130;-7.41243;,
 -40.02785;9.30670;10.03627;,
 -40.02785;13.22920;0.21616;,
 -40.02785;0.01080;0.03006;,
 -40.02785;-0.09320;13.61067;,
 -40.02785;9.50540;-9.74613;,
 -40.02785;-0.10640;-13.28953;,
 -40.02785;-13.30990;0.20186;,
 -40.02785;-9.44140;9.91137;,
 -40.02785;-9.64030;-9.62033;,
 -32.41647;0.00820;-10.52543;,
 -32.57848;7.57130;-7.41243;,
 -4.02749;7.12570;-6.97223;,
 -4.02749;0.01080;-9.40603;,
 -32.57848;7.57130;7.47456;,
 -32.74378;0.00820;10.68817;,
 -4.02749;0.01080;10.62257;,
 -4.02749;7.12570;7.03236;,
 -4.02749;0.01080;10.62257;,
 -4.02749;0.01080;-9.40603;,
 -36.17706;8.10620;7.99576;,
 -35.90446;11.36550;0.02796;,
 -36.37366;0.01050;11.36427;,
 -36.17706;8.10620;-7.93973;,
 -35.98456;0.01050;-11.33423;,
 -36.16576;-11.34940;0.02796;,
 -36.17706;-8.08530;7.99576;,
 -36.17706;-8.08530;-7.93973;,
 -36.17706;-8.08530;7.99576;,
 -36.16576;-11.34940;0.02796;,
 -36.17706;-8.08530;-7.93973;,
 -35.98456;0.01050;-11.33423;,
 -36.17706;8.10620;-7.93973;,
 -36.17706;8.10620;7.99576;,
 -36.37366;0.01050;11.36427;;
 
 40;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;6,7,8,9;,
 4;7,10,11,8;,
 4;9,8,12,13;,
 4;8,11,14,12;,
 4;15,16,17,18;,
 4;16,19,20,17;,
 4;21,22,23,24;,
 4;22,25,26,23;,
 4;24,23,27,28;,
 4;23,26,29,27;,
 4;30,31,32,33;,
 4;4,30,33,5;,
 4;34,35,36,37;,
 4;35,0,3,36;,
 4;3,2,7,6;,
 4;38,3,6,9;,
 4;2,5,10,7;,
 4;5,39,11,10;,
 4;16,15,13,12;,
 4;15,38,9,13;,
 4;39,19,14,11;,
 4;19,16,12,14;,
 4;40,41,22,21;,
 4;42,40,21,24;,
 4;41,43,25,22;,
 4;43,44,26,25;,
 4;45,46,28,27;,
 4;46,42,24,28;,
 4;44,47,29,26;,
 4;47,45,27,29;,
 4;48,49,1,0;,
 4;49,50,4,1;,
 4;50,51,30,4;,
 4;51,52,31,30;,
 4;17,20,43,41;,
 4;18,17,41,40;,
 4;53,54,35,34;,
 4;54,48,0,35;;
 
 MeshMaterialList {
  17;
  40;
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9;;
  Material {
   0.008000;0.008000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.056000;0.056000;0.056000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.008000;0.008000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.696000;0.400000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.696000;0.400000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.696000;0.400000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.400000;0.312000;0.072000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.008000;0.008000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.112000;0.264000;0.144000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.144000;0.216000;0.040000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.616000;0.392000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.048000;0.080000;0.176000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.064000;0.064000;0.064000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.424000;0.136000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.016000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  42;
  0.358966;-0.662389;0.657559;,
  0.341342;-0.939937;0.002119;,
  0.346061;-0.667604;-0.659202;,
  0.415236;-0.661574;0.624419;,
  0.409313;-0.912392;0.002080;,
  0.421059;-0.630330;-0.652222;,
  0.409660;-0.001537;0.912237;,
  0.392664;-0.001320;-0.919681;,
  0.419449;0.678689;0.602863;,
  0.399003;0.916948;0.001910;,
  0.424769;0.648521;-0.631658;,
  0.353838;0.662275;0.660447;,
  0.331521;0.943445;0.002279;,
  0.341796;0.667537;-0.661490;,
  0.371524;-0.001474;0.928422;,
  0.350616;-0.001727;-0.936518;,
  0.883308;-0.343226;0.319317;,
  0.927465;-0.373905;0.002003;,
  1.000000;-0.000000;0.000000;,
  0.929557;-0.001457;0.368675;,
  0.885807;-0.320539;-0.335562;,
  0.919616;-0.001299;-0.392816;,
  0.921518;0.388331;0.001882;,
  0.885029;0.352466;0.304124;,
  0.887331;0.330794;-0.321276;,
  -1.000000;0.000000;0.000000;,
  0.107974;-0.712232;0.693590;,
  0.113517;-0.993536;0.000012;,
  0.118631;-0.699184;-0.705031;,
  0.121855;-0.000008;-0.992548;,
  0.125719;0.707125;-0.695823;,
  0.124844;0.992176;0.000007;,
  0.114941;0.720089;0.684295;,
  0.104160;-0.000012;0.994561;,
  0.440835;0.897577;0.004483;,
  0.493081;0.616065;0.614277;,
  0.533399;-0.002842;0.845859;,
  0.462078;0.630376;-0.623787;,
  0.478676;-0.003375;-0.877985;,
  0.507991;-0.612238;0.605896;,
  0.470288;-0.882503;0.004138;,
  0.475724;-0.626889;-0.617006;;
  40;
  4;26,27,4,3;,
  4;27,28,5,4;,
  4;16,17,18,19;,
  4;17,20,21,18;,
  4;19,18,22,23;,
  4;18,21,24,22;,
  4;8,9,31,32;,
  4;9,10,30,31;,
  4;25,25,25,25;,
  4;25,25,25,25;,
  4;25,25,25,25;,
  4;25,25,25,25;,
  4;29,30,10,7;,
  4;28,29,7,5;,
  4;32,33,6,8;,
  4;33,26,3,6;,
  4;3,4,17,16;,
  4;6,3,16,19;,
  4;4,5,20,17;,
  4;5,7,21,20;,
  4;9,8,23,22;,
  4;8,6,19,23;,
  4;7,10,24,21;,
  4;10,9,22,24;,
  4;11,12,34,35;,
  4;14,11,35,36;,
  4;12,13,37,34;,
  4;13,15,38,37;,
  4;1,0,39,40;,
  4;0,14,36,39;,
  4;15,2,41,38;,
  4;2,1,40,41;,
  4;0,1,27,26;,
  4;1,2,28,27;,
  4;2,15,29,28;,
  4;15,13,30,29;,
  4;31,30,13,12;,
  4;32,31,12,11;,
  4;11,14,33,32;,
  4;14,0,26,33;;
 }
 MeshTextureCoords {
  55;
  0.375000;0.027970;,
  0.500000;0.027970;,
  0.500000;0.250000;,
  0.375000;0.250000;,
  0.625000;0.027970;,
  0.625000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.500000;0.375000;,
  0.375000;0.375000;,
  0.625000;0.250000;,
  0.625000;0.375000;,
  0.500000;0.500000;,
  0.375000;0.500000;,
  0.625000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.500000;0.722030;,
  0.375000;0.722030;,
  0.625000;0.500000;,
  0.625000;0.722030;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.500000;0.875000;,
  0.375000;0.875000;,
  0.625000;0.750000;,
  0.625000;0.875000;,
  0.500000;1.000000;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.750000;0.027970;,
  0.875000;0.027970;,
  0.875000;0.250000;,
  0.750000;0.250000;,
  0.125000;0.027970;,
  0.250000;0.027970;,
  0.250000;0.250000;,
  0.125000;0.250000;,
  0.375000;0.375000;,
  0.625000;0.375000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.375000;0.875000;,
  0.625000;0.750000;,
  0.625000;0.875000;,
  0.500000;1.000000;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.375000;0.000000;,
  0.500000;0.000000;,
  0.625000;0.000000;,
  0.750000;0.000000;,
  0.875000;0.000000;,
  0.125000;0.000000;,
  0.250000;0.000000;;
 }
}
=======
>>>>>>> a6583b3a48f3fc4c322b5886eee8e528e94535f9
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
 55;
 -32.57848;-7.55490;7.47456;,
 -32.56897;-10.60060;0.03106;,
 -4.02749;-9.93860;0.03006;,
 -4.02749;-7.10390;7.03236;,
 -32.57848;-7.55490;-7.41243;,
 -4.02749;-7.10390;-6.97223;,
 -0.16539;-4.61680;4.95056;,
 -0.16539;-5.28070;0.17286;,
 -0.16539;0.01080;0.03007;,
 -0.16539;-0.07750;5.87696;,
 -0.16539;-4.72460;-4.60494;,
 -0.16539;-0.08010;-5.24174;,
 -0.16539;4.96600;0.17526;,
 -0.16539;4.46180;5.02057;,
 -0.16539;4.56440;-4.66994;,
 -4.02749;7.12570;7.03236;,
 -4.02749;9.23010;0.03006;,
 -32.34917;10.53570;0.03106;,
 -32.57848;7.57130;7.47456;,
 -4.02749;7.12570;-6.97223;,
 -32.57848;7.57130;-7.41243;,
 -40.02785;9.30670;10.03627;,
 -40.02785;13.22920;0.21616;,
 -40.02785;0.01080;0.03006;,
 -40.02785;-0.09320;13.61067;,
 -40.02785;9.50540;-9.74613;,
 -40.02785;-0.10640;-13.28953;,
 -40.02785;-13.30990;0.20186;,
 -40.02785;-9.44140;9.91137;,
 -40.02785;-9.64030;-9.62033;,
 -32.41647;0.00820;-10.52543;,
 -32.57848;7.57130;-7.41243;,
 -4.02749;7.12570;-6.97223;,
 -4.02749;0.01080;-9.40603;,
 -32.57848;7.57130;7.47456;,
 -32.74378;0.00820;10.68817;,
 -4.02749;0.01080;10.62257;,
 -4.02749;7.12570;7.03236;,
 -4.02749;0.01080;10.62257;,
 -4.02749;0.01080;-9.40603;,
 -36.17706;8.10620;7.99576;,
 -35.90446;11.36550;0.02796;,
 -36.37366;0.01050;11.36427;,
 -36.17706;8.10620;-7.93973;,
 -35.98456;0.01050;-11.33423;,
 -36.16576;-11.34940;0.02796;,
 -36.17706;-8.08530;7.99576;,
 -36.17706;-8.08530;-7.93973;,
 -36.17706;-8.08530;7.99576;,
 -36.16576;-11.34940;0.02796;,
 -36.17706;-8.08530;-7.93973;,
 -35.98456;0.01050;-11.33423;,
 -36.17706;8.10620;-7.93973;,
 -36.17706;8.10620;7.99576;,
 -36.37366;0.01050;11.36427;;
 
 40;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;6,7,8,9;,
 4;7,10,11,8;,
 4;9,8,12,13;,
 4;8,11,14,12;,
 4;15,16,17,18;,
 4;16,19,20,17;,
 4;21,22,23,24;,
 4;22,25,26,23;,
 4;24,23,27,28;,
 4;23,26,29,27;,
 4;30,31,32,33;,
 4;4,30,33,5;,
 4;34,35,36,37;,
 4;35,0,3,36;,
 4;3,2,7,6;,
 4;38,3,6,9;,
 4;2,5,10,7;,
 4;5,39,11,10;,
 4;16,15,13,12;,
 4;15,38,9,13;,
 4;39,19,14,11;,
 4;19,16,12,14;,
 4;40,41,22,21;,
 4;42,40,21,24;,
 4;41,43,25,22;,
 4;43,44,26,25;,
 4;45,46,28,27;,
 4;46,42,24,28;,
 4;44,47,29,26;,
 4;47,45,27,29;,
 4;48,49,1,0;,
 4;49,50,4,1;,
 4;50,51,30,4;,
 4;51,52,31,30;,
 4;17,20,43,41;,
 4;18,17,41,40;,
 4;53,54,35,34;,
 4;54,48,0,35;;
 
 MeshMaterialList {
  17;
  40;
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9;;
  Material {
   0.008000;0.008000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.056000;0.056000;0.056000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.008000;0.008000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.696000;0.400000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.696000;0.400000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.696000;0.400000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.400000;0.312000;0.072000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.008000;0.008000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.112000;0.264000;0.144000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.144000;0.216000;0.040000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.616000;0.392000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.048000;0.080000;0.176000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.064000;0.064000;0.064000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.424000;0.136000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.016000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  42;
  0.358966;-0.662389;0.657559;,
  0.341342;-0.939937;0.002119;,
  0.346061;-0.667604;-0.659202;,
  0.415236;-0.661574;0.624419;,
  0.409313;-0.912392;0.002080;,
  0.421059;-0.630330;-0.652222;,
  0.409660;-0.001537;0.912237;,
  0.392664;-0.001320;-0.919681;,
  0.419449;0.678689;0.602863;,
  0.399003;0.916948;0.001910;,
  0.424769;0.648521;-0.631658;,
  0.353838;0.662275;0.660447;,
  0.331521;0.943445;0.002279;,
  0.341796;0.667537;-0.661490;,
  0.371524;-0.001474;0.928422;,
  0.350616;-0.001727;-0.936518;,
  0.883308;-0.343226;0.319317;,
  0.927465;-0.373905;0.002003;,
  1.000000;-0.000000;0.000000;,
  0.929557;-0.001457;0.368675;,
  0.885807;-0.320539;-0.335562;,
  0.919616;-0.001299;-0.392816;,
  0.921518;0.388331;0.001882;,
  0.885029;0.352466;0.304124;,
  0.887331;0.330794;-0.321276;,
  -1.000000;0.000000;0.000000;,
  0.107974;-0.712232;0.693590;,
  0.113517;-0.993536;0.000012;,
  0.118631;-0.699184;-0.705031;,
  0.121855;-0.000008;-0.992548;,
  0.125719;0.707125;-0.695823;,
  0.124844;0.992176;0.000007;,
  0.114941;0.720089;0.684295;,
  0.104160;-0.000012;0.994561;,
  0.440835;0.897577;0.004483;,
  0.493081;0.616065;0.614277;,
  0.533399;-0.002842;0.845859;,
  0.462078;0.630376;-0.623787;,
  0.478676;-0.003375;-0.877985;,
  0.507991;-0.612238;0.605896;,
  0.470288;-0.882503;0.004138;,
  0.475724;-0.626889;-0.617006;;
  40;
  4;26,27,4,3;,
  4;27,28,5,4;,
  4;16,17,18,19;,
  4;17,20,21,18;,
  4;19,18,22,23;,
  4;18,21,24,22;,
  4;8,9,31,32;,
  4;9,10,30,31;,
  4;25,25,25,25;,
  4;25,25,25,25;,
  4;25,25,25,25;,
  4;25,25,25,25;,
  4;29,30,10,7;,
  4;28,29,7,5;,
  4;32,33,6,8;,
  4;33,26,3,6;,
  4;3,4,17,16;,
  4;6,3,16,19;,
  4;4,5,20,17;,
  4;5,7,21,20;,
  4;9,8,23,22;,
  4;8,6,19,23;,
  4;7,10,24,21;,
  4;10,9,22,24;,
  4;11,12,34,35;,
  4;14,11,35,36;,
  4;12,13,37,34;,
  4;13,15,38,37;,
  4;1,0,39,40;,
  4;0,14,36,39;,
  4;15,2,41,38;,
  4;2,1,40,41;,
  4;0,1,27,26;,
  4;1,2,28,27;,
  4;2,15,29,28;,
  4;15,13,30,29;,
  4;31,30,13,12;,
  4;32,31,12,11;,
  4;11,14,33,32;,
  4;14,0,26,33;;
 }
 MeshTextureCoords {
  55;
  0.375000;0.027970;,
  0.500000;0.027970;,
  0.500000;0.250000;,
  0.375000;0.250000;,
  0.625000;0.027970;,
  0.625000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.500000;0.375000;,
  0.375000;0.375000;,
  0.625000;0.250000;,
  0.625000;0.375000;,
  0.500000;0.500000;,
  0.375000;0.500000;,
  0.625000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.500000;0.722030;,
  0.375000;0.722030;,
  0.625000;0.500000;,
  0.625000;0.722030;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.500000;0.875000;,
  0.375000;0.875000;,
  0.625000;0.750000;,
  0.625000;0.875000;,
  0.500000;1.000000;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.750000;0.027970;,
  0.875000;0.027970;,
  0.875000;0.250000;,
  0.750000;0.250000;,
  0.125000;0.027970;,
  0.250000;0.027970;,
  0.250000;0.250000;,
  0.125000;0.250000;,
  0.375000;0.375000;,
  0.625000;0.375000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.375000;0.875000;,
  0.625000;0.750000;,
  0.625000;0.875000;,
  0.500000;1.000000;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.375000;0.000000;,
  0.500000;0.000000;,
  0.625000;0.000000;,
  0.750000;0.000000;,
  0.875000;0.000000;,
  0.125000;0.000000;,
  0.250000;0.000000;;
 }
}
<<<<<<< HEAD
=======
>>>>>>> f3d5af8f619feb1bdd1b24797dcdecaaaead1bb0
>>>>>>> a6583b3a48f3fc4c322b5886eee8e528e94535f9
