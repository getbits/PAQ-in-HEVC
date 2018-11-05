# PAQ-in-HEVC
PAQ is adopted in probability estimation in the entropy coding process of HEVC16.6-JEM5.01. 

Macro Control:
#define NN_BASED_CABAC    1  //   probability estimation control
#define RDO_MAP           0 // RDO modification

Added Files:
TComContextMixer.h
TComContextMixer.cpp


References: 
[1] http://mattmahoney.net/dc/nnword.html  Improving Neural Network Text Compression with Word-Oriented Contexts
[2] http://mattmahoney.net/dc/paq.html  The PAQ Data Compression Programs
[3] http://phenix.it-sudparis.eu/jvet/  
