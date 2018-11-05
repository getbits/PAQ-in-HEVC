


#if NN_BASED_CABAC
// 8, 16, 32 bit unsigned types (adjust as appropriate)
typedef unsigned char  U8;
typedef unsigned short U16;
typedef unsigned int   U32;
/////////////////////// Global context /////////////////////////

//int level = DEFAULT_OPTION;  // Compression level 0 to 9
//#define MEM (0x10000<<level)
//int y = 0;  // Last bit, 0 or 1, set by encoder

// Global context set by Predictor and available to all models.
extern int c0; // Last 0-7 bits of the partial byte with a leading 1 bit (1-255)
extern U32 c4; // Last 4 whole bytes, packed.  Last byte is bits 0-7.
extern int bpos; // bits in c0 (0 to 7)
//extern Buf buf;  // Rotating input queue set by Predictor
extern int pos;

//////////////////////////// Predictor /////////////////////////
//估计下一个bit的概率值
// A Predictor estimates the probability that the next bit of
// uncompressed data is 1.  Methods:
// p() returns P(1) as a 12 bit number (0-4095).
// update(y) trains the predictor with the actual bit (0 or 1).

class Predictor {
	int pr;  // next prediction
public:
	Predictor();
	int p() const
	{
		assert(pr >= 0 && pr < 4096); return pr;  //return的是下一个bit的预测概率p(1) 并且是12 bit的位深，
	}
	void update();  //train the predictor with 实际的bit的值
};

#endif 