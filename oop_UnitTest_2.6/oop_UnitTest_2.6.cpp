#include "pch.h"
#include "CppUnitTest.h"
#include "../oop_laba_2.6/Vector3D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace oopUnitTest26
{
	TEST_CLASS(oopUnitTest26)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Vector3D::Triad a;
			Assert::AreEqual(a.init(2, 4, 6), true);
		}
	};
}
