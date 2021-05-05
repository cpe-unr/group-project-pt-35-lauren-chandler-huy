//Author: Huy Tran, Lauren Feldman
//Date: 5/3/21
//Group Project 

#ifndef NORMAL_H
#define NORMAL_H

template <typename A>
class Normal
{
	float percentDb;

public:
	Normal(float newPercent) : percentDb(newPercent) {};

	float getPercentDb () const
	{
		return percentDb;
	}

	void setPercentDb (float newPercent)
	{
		percentDb = newPercent;
	}

	void processBuffer(A buffer, int bufferSize, int bit_size, bool stereo)
	{
		float highDecib, lowDecib;
		
		if(bit_size > 255)
		{
			if(stereo)
			{
				if (percentDb >= 0 && percentDb <= 1)
				{
					highDecib = 0;
					lowDecib = 0;
					for (int i = 0; i < bufferSize; i+=2)
					{						
						if (buffer[i] > highDecib)
						{
							highDecib = buffer[i];
						}
						if (buffer[i] < lowDecib)
						{
							lowDecib = buffer[i];
						}
					}	
					for (int i = 0; i < bufferSize; i+=2)
					{
						if (buffer[i] < highDecib && buffer[i] > lowDecib)
						{
							if (buffer[i] < 0)
							{
								buffer[i] = buffer[i] - (percentDb * lowDecib);
							}
							else
							{
								buffer[i] = buffer[i] + (percentDb * highDecib);
							}
						}
					}
					
					highDecib = 0;
					lowDecib = 0;
					for (int i = 1; i < bufferSize; i+=2)
					{				
						if (buffer[i] > highDecib)
						{
							highDecib = buffer[i];
						}
						if (buffer[i] < lowDecib)
						{
							lowDecib = buffer[i];
						}
					}	
					for (int i = 1; i < bufferSize; i+=2)
					{
						if (buffer[i] < highDecib && buffer[i] > lowDecib)
						{
							if (buffer[i] < 0)
							{
								buffer[i] = buffer[i] - (percentDb * lowDecib);
							}
							else
							{
								buffer[i] = buffer[i] + (percentDb * highDecib);
							}
						}
					}
				}
			}
			else
			{
				if (percentDb >= 0 && percentDb <= 1)
				{
					highDecib = 0;
					lowDecib = 0;
					
					for (int i = 0; i < bufferSize; i++)
					{
						if (buffer[i] > highDecib)
						{
							highDecib = buffer[i];
						}
						if (buffer[i] < lowDecib)
						{
							lowDecib = buffer[i];
						}
					}
					for (int i = 0; i < bufferSize; i++)
					{
						if (buffer[i] < highDecib && buffer[i] > lowDecib)
						{
							if (buffer[i] < 0)
							{
								buffer[i] = buffer[i] - (percentDb * lowDecib);
							}
							else
							{
								buffer[i] = buffer[i] + (percentDb * highDecib);
							}
						}
					}
				}
			}
		}
		else
		{
			if(stereo)
			{
				highDecib = 128;
				lowDecib = 128;
				for (int i = 0; i < bufferSize; i+=2)
				{						
					if (buffer[i] > highDecib)
					{
						highDecib = buffer[i];
					}
					if (buffer[i] < lowDecib)
					{
						lowDecib = buffer[i];
					}
				}	
				for (int i = 0; i < bufferSize; i+=2)
				{
					if (buffer[i] < highDecib && buffer[i] > lowDecib)
					{
						if (buffer[i] < 128)
						{
							buffer[i] = buffer[i] - (percentDb * lowDecib);
						}
						else
						{
							buffer[i] = buffer[i] + (percentDb * highDecib);
						}
					}
				}
				highDecib = 128;
				lowDecib = 128;
				for (int i = 1; i < bufferSize; i+=2)
				{				
					if (buffer[i] > highDecib)
					{
						highDecib = buffer[i];
					}
					if (buffer[i] < lowDecib)
					{
						lowDecib = buffer[i];
					}
				}	
				for (int i = 1; i < bufferSize; i+=2)
				{
					if (buffer[i] < highDecib && buffer[i] > lowDecib)
					{
						if (buffer[i] < 128)
						{
							buffer[i] = buffer[i] - (percentDb * lowDecib);
						}
						else
						{
							buffer[i] = buffer[i] + (percentDb * highDecib);
						}
					}
				}
			}
			else
			{
				if (percentDb >= 0 && percentDb <= 1)
				{
					highDecib = 128;
					lowDecib = 128;
					
					for (int i = 0; i < bufferSize; i++)
					{
						if (buffer[i] > highDecib)
						{
							highDecib = buffer[i];
						}
						if (buffer[i] < lowDecib)
						{
							lowDecib = buffer[i];
						}
					}
					for (int i = 0; i < bufferSize; i++)
					{
						if (buffer[i] < highDecib && buffer[i] > lowDecib)
						{
							if (buffer[i] < 128)
							{
								buffer[i] = buffer[i] - (percentDb * lowDecib);
							}
							else
							{
								buffer[i] = buffer[i] + (percentDb * highDecib);
							}
						}
					}
				}
			}
		}
	}
};

#include "Normal.cpp"
#endif //NORMAL_H
