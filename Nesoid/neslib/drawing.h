#define SCREEN_WIDTH 320
#define SCREEN_OFFS 32

void DrawTextLineBG(uint8 *dest)
{
 int x,y;
 static int otable[7]={81,49,30,17,8,3,0};
        //100,40,15,10,7,5,2};
 for(y=0;y<14;y++)
 {
  int offs;

  if(y>=7) offs=otable[13-y];
  else offs=otable[y];

  for(x=offs;x<(256-offs);x++)
   dest[y*SCREEN_WIDTH+x]=(dest[y*SCREEN_WIDTH+x]&0x0f)|0xC0;//&=0xe0; //0x80;
 }
}

static void DrawMessage(void)
{
 if(howlong)
  {
   uint8 *t;
   howlong--;
   t=XBuf+(FSettings.LastSLine-16)*SCREEN_WIDTH+SCREEN_OFFS;
   if(t>=XBuf)
   {
    DrawTextLineBG(t);
    DrawTextTrans(t+3*SCREEN_WIDTH+(128-strlen(errmsg)*4),SCREEN_WIDTH,(uint8 *)errmsg,4);
   }
  }
}

uint8 fontdata2[2048] =
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7e,0x81,0xa5,0x81,0xbd,0x99,0x81,0x7e,0x7e,0xff,0xdb,0xff,0xc3,0xe7,0xff,0x7e,0x36,0x7f,0x7f,0x7f,0x3e,0x1c,0x08,0x00,0x08,0x1c,0x3e,0x7f,0x3e,0x1c,0x08,0x00,0x1c,0x3e,0x1c,0x7f,0x7f,0x3e,0x1c,0x3e,0x08,0x08,0x1c,0x3e,0x7f,0x3e,0x1c,0x3e,0x00,0x00,0x18,0x3c,0x3c,0x18,0x00,0x00,0xff,0xff,0xe7,0xc3,0xc3,0xe7,0xff,0xff,0x00,0x3c,0x66,0x42,0x42,0x66,0x3c,0x00,0xff,0xc3,0x99,0xbd,0xbd,0x99,0xc3,0xff,0xf0,0xe0,0xf0,0xbe,0x33,0x33,0x33,0x1e,0x3c,0x66,0x66,0x66,0x3c,0x18,0x7e,0x18,0xfc,0xcc,0xfc,0x0c,0x0c,0x0e,0x0f,0x07,0xfe,0xc6,0xfe,0xc6,0xc6,0xe6,0x67,0x03,0x99,0x5a,0x3c,0xe7,0xe7,0x3c,0x5a,0x99,0x01,0x07,0x1f,0x7f,0x1f,0x07,0x01,0x00,0x40,0x70,0x7c,0x7f,0x7c,0x70,0x40,0x00,0x18,0x3c,0x7e,0x18,0x18,0x7e,0x3c,0x18,0x66,0x66,0x66,0x66,0x66,0x00,0x66,0x00,0xfe,0xdb,0xdb,0xde,0xd8,0xd8,0xd8,0x00,0x7c,0xc6,0x1c,0x36,0x36,0x1c,0x33,0x1e,0x00,0x00,0x00,0x00,0x7e,0x7e,0x7e,0x00,0x18,0x3c,0x7e,0x18,0x7e,0x3c,0x18,0xff,0x18,0x3c,0x7e,0x18,0x18,0x18,0x18,0x00,0x18,0x18,0x18,0x18,0x7e,0x3c,0x18,0x00,0x00,0x18,0x30,0x7f,0x30,0x18,0x00,0x00,0x00,0x0c,0x06,0x7f,0x06,0x0c,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x7f,0x00,0x00,0x00,0x24,0x66,0xff,0x66,0x24,0x00,0x00,0x00,0x18,0x3c,0x7e,0xff,0xff,0x00,0x00,0x00,0xff,0xff,0x7e,0x3c,0x18,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x1e,0x1e,0x0c,0x0c,0x00,0x0c,0x00,0x36,0x36,0x36,0x00,0x00,0x00,0x00,0x00,0x36,0x36,0x7f,0x36,0x7f,0x36,0x36,0x00,0x0c,0x3e,0x03,0x1e,0x30,0x1f,0x0c,0x00,0x00,0x63,0x33,0x18,0x0c,0x66,0x63,0x00,0x1c,0x36,0x1c,0x6e,0x3b,0x33,0x6e,0x00,0x06,0x06,0x03,0x00,0x00,0x00,0x00,0x00,0x18,0x0c,0x06,0x06,0x06,0x0c,0x18,0x00,0x06,0x0c,0x18,0x18,0x18,0x0c,0x06,0x00,0x00,0x66,0x3c,0xff,0x3c,0x66,0x00,0x00,0x00,0x0c,0x0c,0x3f,0x0c,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x0c,0x06,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x0c,0x00,0x60,0x30,0x18,0x0c,0x06,0x03,0x01,0x00,0x3e,0x63,0x73,0x7b,0x6f,0x67,0x3e,0x00,0x0c,0x0e,0x0c,0x0c,0x0c,0x0c,0x3f,0x00,0x1e,0x33,0x30,0x1c,0x06,0x33,0x3f,0x00,0x1e,0x33,0x30,0x1c,0x30,0x33,0x1e,0x00,0x38,0x3c,0x36,0x33,0x7f,0x30,0x78,0x00,0x3f,0x03,0x1f,0x30,0x30,0x33,0x1e,0x00,0x1c,0x06,0x03,0x1f,0x33,0x33,0x1e,0x00,0x3f,0x33,0x30,0x18,0x0c,0x0c,0x0c,0x00,0x1e,0x33,0x33,0x1e,0x33,0x33,0x1e,0x00,0x1e,0x33,0x33,0x3e,0x30,0x18,0x0e,0x00,0x00,0x0c,0x0c,0x00,0x00,0x0c,0x0c,0x00,0x00,0x0c,0x0c,0x00,0x00,0x0c,0x0c,0x06,0x18,0x0c,0x06,0x03,0x06,0x0c,0x18,0x00,0x00,0x00,0x3f,0x00,0x00,0x3f,0x00,0x00,0x06,0x0c,0x18,0x30,0x18,0x0c,0x06,0x00,0x1e,0x33,0x30,0x18,0x0c,0x00,0x0c,0x00,
0x3e,0x63,0x7b,0x7b,0x7b,0x03,0x1e,0x00,0x0c,0x1e,0x33,0x33,0x3f,0x33,0x33,0x00,0x3f,0x66,0x66,0x3e,0x66,0x66,0x3f,0x00,0x3c,0x66,0x03,0x03,0x03,0x66,0x3c,0x00,0x1f,0x36,0x66,0x66,0x66,0x36,0x1f,0x00,0x7f,0x46,0x16,0x1e,0x16,0x46,0x7f,0x00,0x7f,0x46,0x16,0x1e,0x16,0x06,0x0f,0x00,0x3c,0x66,0x03,0x03,0x73,0x66,0x7c,0x00,0x33,0x33,0x33,0x3f,0x33,0x33,0x33,0x00,0x1e,0x0c,0x0c,0x0c,0x0c,0x0c,0x1e,0x00,0x78,0x30,0x30,0x30,0x33,0x33,0x1e,0x00,0x67,0x66,0x36,0x1e,0x36,0x66,0x67,0x00,0x0f,0x06,0x06,0x06,0x46,0x66,0x7f,0x00,0x63,0x77,0x7f,0x7f,0x6b,0x63,0x63,0x00,0x63,0x67,0x6f,0x7b,0x73,0x63,0x63,0x00,0x1c,0x36,0x63,0x63,0x63,0x36,0x1c,0x00,0x3f,0x66,0x66,0x3e,0x06,0x06,0x0f,0x00,0x1e,0x33,0x33,0x33,0x3b,0x1e,0x38,0x00,0x3f,0x66,0x66,0x3e,0x36,0x66,0x67,0x00,0x1e,0x33,0x07,0x0e,0x38,0x33,0x1e,0x00,0x3f,0x2d,0x0c,0x0c,0x0c,0x0c,0x1e,0x00,0x33,0x33,0x33,0x33,0x33,0x33,0x3f,0x00,0x33,0x33,0x33,0x33,0x33,0x1e,0x0c,0x00,0x63,0x63,0x63,0x6b,0x7f,0x77,0x63,0x00,0x63,0x63,0x36,0x1c,0x1c,0x36,0x63,0x00,0x33,0x33,0x33,0x1e,0x0c,0x0c,0x1e,0x00,0x7f,0x63,0x31,0x18,0x4c,0x66,0x7f,0x00,0x1e,0x06,0x06,0x06,0x06,0x06,0x1e,0x00,0x03,0x06,0x0c,0x18,0x30,0x60,0x40,0x00,0x1e,0x18,0x18,0x18,0x18,0x18,0x1e,0x00,0x08,0x1c,0x36,0x63,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
0x0c,0x0c,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1e,0x30,0x3e,0x33,0x6e,0x00,0x07,0x06,0x06,0x3e,0x66,0x66,0x3b,0x00,0x00,0x00,0x1e,0x33,0x03,0x33,0x1e,0x00,0x38,0x30,0x30,0x3e,0x33,0x33,0x6e,0x00,0x00,0x00,0x1e,0x33,0x3f,0x03,0x1e,0x00,0x1c,0x36,0x06,0x0f,0x06,0x06,0x0f,0x00,0x00,0x00,0x6e,0x33,0x33,0x3e,0x30,0x1f,0x07,0x06,0x36,0x6e,0x66,0x66,0x67,0x00,0x0c,0x00,0x0e,0x0c,0x0c,0x0c,0x1e,0x00,0x30,0x00,0x30,0x30,0x30,0x33,0x33,0x1e,0x07,0x06,0x66,0x36,0x1e,0x36,0x67,0x00,0x0e,0x0c,0x0c,0x0c,0x0c,0x0c,0x1e,0x00,0x00,0x00,0x33,0x7f,0x7f,0x6b,0x63,0x00,0x00,0x00,0x1f,0x33,0x33,0x33,0x33,0x00,0x00,0x00,0x1e,0x33,0x33,0x33,0x1e,0x00,0x00,0x00,0x3b,0x66,0x66,0x3e,0x06,0x0f,0x00,0x00,0x6e,0x33,0x33,0x3e,0x30,0x78,0x00,0x00,0x3b,0x6e,0x66,0x06,0x0f,0x00,0x00,0x00,0x3e,0x03,0x1e,0x30,0x1f,0x00,0x08,0x0c,0x3e,0x0c,0x0c,0x2c,0x18,0x00,0x00,0x00,0x33,0x33,0x33,0x33,0x6e,0x00,0x00,0x00,0x33,0x33,0x33,0x1e,0x0c,0x00,0x00,0x00,0x63,0x6b,0x7f,0x7f,0x36,0x00,0x00,0x00,0x63,0x36,0x1c,0x36,0x63,0x00,0x00,0x00,0x33,0x33,0x33,0x3e,0x30,0x1f,0x00,0x00,0x3f,0x19,0x0c,0x26,0x3f,0x00,0x38,0x0c,0x0c,0x07,0x0c,0x0c,0x38,0x00,0x18,0x18,0x18,0x00,0x18,0x18,0x18,0x00,0x07,0x0c,0x0c,0x38,0x0c,0x0c,0x07,0x00,0x6e,0x3b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x1c,0x36,0x63,0x63,0x7f,0x00,
0x1e,0x33,0x03,0x33,0x1e,0x18,0x30,0x1e,0x00,0x33,0x00,0x33,0x33,0x33,0x7e,0x00,0x38,0x00,0x1e,0x33,0x3f,0x03,0x1e,0x00,0x7e,0xc3,0x3c,0x60,0x7c,0x66,0xfc,0x00,0x33,0x00,0x1e,0x30,0x3e,0x33,0x7e,0x00,0x07,0x00,0x1e,0x30,0x3e,0x33,0x7e,0x00,0x0c,0x0c,0x1e,0x30,0x3e,0x33,0x7e,0x00,0x00,0x00,0x1e,0x03,0x03,0x1e,0x30,0x1c,0x7e,0xc3,0x3c,0x66,0x7e,0x06,0x3c,0x00,0x33,0x00,0x1e,0x33,0x3f,0x03,0x1e,0x00,0x07,0x00,0x1e,0x33,0x3f,0x03,0x1e,0x00,0x33,0x00,0x0e,0x0c,0x0c,0x0c,0x1e,0x00,0x3e,0x63,0x1c,0x18,0x18,0x18,0x3c,0x00,0x07,0x00,0x0e,0x0c,0x0c,0x0c,0x1e,0x00,0x63,0x1c,0x36,0x63,0x7f,0x63,0x63,0x00,0x0c,0x0c,0x00,0x1e,0x33,0x3f,0x33,0x00,0x38,0x00,0x3f,0x06,0x1e,0x06,0x3f,0x00,0x00,0x00,0xfe,0x30,0xfe,0x33,0xfe,0x00,0x7c,0x36,0x33,0x7f,0x33,0x33,0x73,0x00,0x1e,0x33,0x00,0x1e,0x33,0x33,0x1e,0x00,0x00,0x33,0x00,0x1e,0x33,0x33,0x1e,0x00,0x00,0x07,0x00,0x1e,0x33,0x33,0x1e,0x00,0x1e,0x33,0x00,0x33,0x33,0x33,0x7e,0x00,0x00,0x07,0x00,0x33,0x33,0x33,0x7e,0x00,0x00,0x33,0x00,0x33,0x33,0x3e,0x30,0x1f,0xc3,0x18,0x3c,0x66,0x66,0x3c,0x18,0x00,0x33,0x00,0x33,0x33,0x33,0x33,0x1e,0x00,0x18,0x18,0x7e,0x03,0x03,0x7e,0x18,0x18,0x1c,0x36,0x26,0x0f,0x06,0x67,0x3f,0x00,0x33,0x33,0x1e,0x3f,0x0c,0x3f,0x0c,0x0c,0x1f,0x33,0x33,0x5f,0x63,0xf3,0x63,0xe3,0x70,0xd8,0x18,0x3c,0x18,0x18,0x1b,0x0e,
0x38,0x00,0x1e,0x30,0x3e,0x33,0x7e,0x00,0x1c,0x00,0x0e,0x0c,0x0c,0x0c,0x1e,0x00,0x00,0x38,0x00,0x1e,0x33,0x33,0x1e,0x00,0x00,0x38,0x00,0x33,0x33,0x33,0x7e,0x00,0x00,0x1f,0x00,0x1f,0x33,0x33,0x33,0x00,0x3f,0x00,0x33,0x37,0x3f,0x3b,0x33,0x00,0x3c,0x36,0x36,0x7c,0x00,0x7e,0x00,0x00,0x1c,0x36,0x36,0x1c,0x00,0x3e,0x00,0x00,0x0c,0x00,0x0c,0x06,0x03,0x33,0x1e,0x00,0x00,0x00,0x00,0x3f,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x3f,0x30,0x30,0x00,0x00,0xc3,0x63,0x33,0x7b,0xcc,0x66,0x33,0xf0,0xc3,0x63,0x33,0xdb,0xec,0xf6,0xf3,0xc0,0x18,0x18,0x00,0x18,0x18,0x18,0x18,0x00,0x00,0xcc,0x66,0x33,0x66,0xcc,0x00,0x00,0x00,0x33,0x66,0xcc,0x66,0x33,0x00,0x00,0x44,0x11,0x44,0x11,0x44,0x11,0x44,0x11,0xaa,0x55,0xaa,0x55,0xaa,0x55,0xaa,0x55,0xdb,0xee,0xdb,0x77,0xdb,0xee,0xdb,0x77,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x1f,0x18,0x18,0x18,0x18,0x18,0x1f,0x18,0x1f,0x18,0x18,0x18,0x6c,0x6c,0x6c,0x6c,0x6f,0x6c,0x6c,0x6c,0x00,0x00,0x00,0x00,0x7f,0x6c,0x6c,0x6c,0x00,0x00,0x1f,0x18,0x1f,0x18,0x18,0x18,0x6c,0x6c,0x6f,0x60,0x6f,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0x00,0x00,0x7f,0x60,0x6f,0x6c,0x6c,0x6c,0x6c,0x6c,0x6f,0x60,0x7f,0x00,0x00,0x00,0x6c,0x6c,0x6c,0x6c,0x7f,0x00,0x00,0x00,0x18,0x18,0x1f,0x18,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0x18,0x18,0x18,
0x18,0x18,0x18,0x18,0xf8,0x00,0x00,0x00,0x18,0x18,0x18,0x18,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0xf8,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0x18,0x18,0x18,0x18,0xff,0x18,0x18,0x18,0x18,0x18,0xf8,0x18,0xf8,0x18,0x18,0x18,0x6c,0x6c,0x6c,0x6c,0xec,0x6c,0x6c,0x6c,0x6c,0x6c,0xec,0x0c,0xfc,0x00,0x00,0x00,0x00,0x00,0xfc,0x0c,0xec,0x6c,0x6c,0x6c,0x6c,0x6c,0xef,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0xff,0x00,0xef,0x6c,0x6c,0x6c,0x6c,0x6c,0xec,0x0c,0xec,0x6c,0x6c,0x6c,0x00,0x00,0xff,0x00,0xff,0x00,0x00,0x00,0x6c,0x6c,0xef,0x00,0xef,0x6c,0x6c,0x6c,0x18,0x18,0xff,0x00,0xff,0x00,0x00,0x00,0x6c,0x6c,0x6c,0x6c,0xff,0x00,0x00,0x00,0x00,0x00,0xff,0x00,0xff,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0xff,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0xfc,0x00,0x00,0x00,0x18,0x18,0xf8,0x18,0xf8,0x00,0x00,0x00,0x00,0x00,0xf8,0x18,0xf8,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0xfc,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0xff,0x6c,0x6c,0x6c,0x18,0x18,0xff,0x18,0xff,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x18,0x18,0x18,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,
0x00,0x00,0x6e,0x3b,0x13,0x3b,0x6e,0x00,0x00,0x1e,0x33,0x1f,0x33,0x1f,0x03,0x03,0x00,0x3f,0x33,0x03,0x03,0x03,0x03,0x00,0x00,0x7f,0x36,0x36,0x36,0x36,0x36,0x00,0x3f,0x33,0x06,0x0c,0x06,0x33,0x3f,0x00,0x00,0x00,0x7e,0x1b,0x1b,0x1b,0x0e,0x00,0x00,0x66,0x66,0x66,0x66,0x3e,0x06,0x03,0x00,0x6e,0x3b,0x18,0x18,0x18,0x18,0x00,0x3f,0x0c,0x1e,0x33,0x33,0x1e,0x0c,0x3f,0x1c,0x36,0x63,0x7f,0x63,0x36,0x1c,0x00,0x1c,0x36,0x63,0x63,0x36,0x36,0x77,0x00,0x38,0x0c,0x18,0x3e,0x33,0x33,0x1e,0x00,0x00,0x00,0x7e,0xdb,0xdb,0x7e,0x00,0x00,0x60,0x30,0x7e,0xdb,0xdb,0x7e,0x06,0x03,0x1c,0x06,0x03,0x1f,0x03,0x06,0x1c,0x00,0x1e,0x33,0x33,0x33,0x33,0x33,0x33,0x00,0x00,0x3f,0x00,0x3f,0x00,0x3f,0x00,0x00,0x0c,0x0c,0x3f,0x0c,0x0c,0x00,0x3f,0x00,0x06,0x0c,0x18,0x0c,0x06,0x00,0x3f,0x00,0x18,0x0c,0x06,0x0c,0x18,0x00,0x3f,0x00,0x70,0xd8,0xd8,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x1b,0x1b,0x0e,0x0c,0x0c,0x00,0x3f,0x00,0x0c,0x0c,0x00,0x00,0x6e,0x3b,0x00,0x6e,0x3b,0x00,0x00,0x1c,0x36,0x36,0x1c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0xf0,0x30,0x30,0x30,0x37,0x36,0x3c,0x38,0x1e,0x36,0x36,0x36,0x36,0x00,0x00,0x00,0x0e,0x18,0x0c,0x06,0x1e,0x00,0x00,0x00,0x00,0x00,0x3c,0x3c,0x3c,0x3c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

void DrawTextTrans(uint8 *dest, uint32 width, uint8 *textmsg, uint8 fgcolor)
{
	uint8 length=strlen((char *)textmsg);
	uint8 x;
	uint8 y;
	uint8 z;

	for(x=0;x<length;x++)
         for(y=0;y<8;y++)
          for(z=0;z<8;z++)
           if((fontdata2[(textmsg[x]<<3)+y]>>z)&1) dest[y*width+(x<<3)+z]=fgcolor;
}

static uint8 sstat[2541] =
{
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x83,0x83,0x83,
0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x80,0x83,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,
0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x80,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x80,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x81,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x80,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x80,0x80,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x83,0x83,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x80,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x80,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x80,0x80,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x80,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80
};

void FCEU_DrawNumberRow(uint8 *XBuf, int *nstatus, int cur)
{
 uint8 *XBaf;
 int z,x,y;

 XBaf=XBuf - 4 + (FSettings.LastSLine-34)*SCREEN_WIDTH+SCREEN_OFFS;
 if(XBaf>=XBuf)
 for(z=1;z<11;z++)
 {
  if(nstatus[z%10])
   {
          for(y=0;y<13;y++)
           for(x=0;x<21;x++)
            XBaf[y*SCREEN_WIDTH+x+z*21+z]=sstat[y*21+x+(z-1)*21*12]^0x80;
   } else {
          for(y=0;y<13;y++)
           for(x=0;x<21;x++)
            if(sstat[y*21+x+(z-1)*21*12]!=0x83)
             XBaf[y*SCREEN_WIDTH+x+z*21+z]=sstat[y*21+x+(z-1)*21*12]^0x80;

            else
             XBaf[y*SCREEN_WIDTH+x+z*21+z]=(XBaf[y*SCREEN_WIDTH+x+z*21+z]&0xF)|0xC0;
   }
  if(cur==z%10)
   {
    for(x=0;x<21;x++)
     XBaf[x+z*21+z*1]=4;
    for(x=1;x<12;x++)
     {
     XBaf[SCREEN_WIDTH*x+z*21+z*1]=
     XBaf[SCREEN_WIDTH*x+z*21+z*1+20]=4;
     }
    for(x=0;x<21;x++)
     XBaf[12*SCREEN_WIDTH+x+z*21+z*1]=4;
   }
  }
}

static uint8 play_slines[]=
{
	0, 0, 1,
	1, 0, 2,
	2, 0, 3,
	3, 0, 4,
	4, 0, 5,
	5, 0, 6,
	6, 0, 7,
	7, 0, 8,
	8, 0, 7,
	9, 0, 6,
	10, 0, 5,
	11, 0, 4,
	12, 0, 3,
	13, 0, 2,
	14, 0, 1,
	99,
};

static uint8 record_slines[]=
{
	0, 5, 9,
	1, 3, 11,
	2, 2, 12,
	3, 1, 13,
	4, 1, 13,
	5, 0, 14,
	6, 0, 14,
	7, 0, 14,
	8, 0, 14,
	9, 0, 14,
	10, 1, 13,
	11, 1, 13,
	12, 2, 12,
	13, 3, 11,
	14, 5, 9,
	99,
};

static uint8 pause_slines[]=
{
	0, 2, 6,
	1, 2, 6,
	2, 2, 6,
	3, 2, 6,
	4, 2, 6,
	5, 2, 6,
	6, 2, 6,
	7, 2, 6,
	8, 2, 6,
	9, 2, 6,
	10, 2, 6,
	11, 2, 6,
	12, 2, 6,
	13, 2, 6,
	14, 2, 6,

	0, 9, 13,
	1, 9, 13,
	2, 9, 13,
	3, 9, 13,
	4, 9, 13,
	5, 9, 13,
	6, 9, 13,
	7, 9, 13,
	8, 9, 13,
	9, 9, 13,
	10, 9, 13,
	11, 9, 13,
	12, 9, 13,
	13, 9, 13,
	14, 9, 13,
	99,
};

static uint8 no_slines[]=
{
	99
};

static uint8* sline_icons[4]=
{
	no_slines,
	play_slines,
	record_slines,
	pause_slines
};

void FCEU_DrawRecordingStatusN(uint8* XBuf, int n)
{
	uint8* slines=sline_icons[n];
	int i;

	XBuf += (FSettings.LastSLine-28)*SCREEN_WIDTH+SCREEN_OFFS + 240 + 255;
	for(i=0; slines[i]!=99; i+=3)
	{
		int y=slines[i];
		uint8* dest=XBuf+(y*SCREEN_WIDTH);
		int x;
		for(x=slines[i+1]; x!=slines[i+2]; ++x)
			dest[x]=0;
	}

	XBuf -= 255;
	for(i=0; slines[i]!=99; i+=3)
	{
		int y=slines[i];
		uint8* dest=XBuf+(y*SCREEN_WIDTH);
		int x;
		for(x=slines[i+1]; x!=slines[i+2]; ++x)
			dest[x]=4;
	}
}
