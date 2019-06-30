// C++ Matrix Multiply
// Nick Michael

#include <iostream>
#include <vector>
#include <numeric>
#include <ctime>

#define VFLOAT std::vector<float>
#define BPOINT std::cout<<"Check!"<<std::endl


std::vector<std::vector<float> > Initialize(std::vector<float> x)
{
	std::vector<std::vector<float> > z;
	for(size_t i = 0; i < 1000; i++)
	{
		z.push_back(x);
	}
	return z;
}


class mmul
{
	private:
		std::vector<std::vector<float> > a, b, c;

	public:
		mmul()
		{
			std::vector<float> u(1000, 0.0);
			a = Initialize(u); b = Initialize(u);
			c = Initialize(u);
		}

		~mmul()
		{
			std::cout << "\nDestructor Called\n" << std::endl;
		}
		
		std::vector<VFLOAT > getA() const {return a;}
		std::vector<VFLOAT > getB() const {return b;}
		std::vector<VFLOAT > getC() const {return c;}

		void Populate(std::vector<VFLOAT > &x, std::vector<VFLOAT > &y)
		{
			float zi, zj;
			for(size_t i = 0; i < 1000; i++)
				for (size_t j = 0; j < 1000; j++)
				{
					zi = i; zj = j;
					zi /= 1000; zj /= 1000;
					x[i][j] = (zi*zi + zj*zj)/2.0;
					y[i][j] = (zi*zj + zi*zj)/2.0;
				}
		}

		void Multiply(std::vector<VFLOAT > x, std::vector<VFLOAT > y,
			std::vector<VFLOAT > &z)
		{
			double start = clock()/(CLOCKS_PER_SEC*1.0);
			std::vector<float> m(1000, 0.0);
			for(size_t i = 0; i < 1000; i++)
				for(size_t j = 0; j < 1000; j++)
				{
					for(size_t k = 0; k < 1000; k++)
						m[k] = x[i][k]*y[j][k];
					z[i][j] = std::accumulate(m.begin(), m.end(), 0);
				}
			double finish = clock()/(CLOCKS_PER_SEC*1.0);
			double ftime = finish - start;
			std::cout << '\n' << ftime << std::endl;
		}
};


int main()
{
	std::vector<std::vector<float> > a, b, c;
	mmul tcheck;
	a = tcheck.getA();
	b = tcheck.getB();
	c = tcheck.getC();
	tcheck.Populate(a, b);
	tcheck.Multiply(a, b, c);
	return 0;
}