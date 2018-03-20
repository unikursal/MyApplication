#include <limits.h>
#include <typeinfo.h>

#include "IProcessor.h"
#include "ProcessWithWord.h"
#include "ProcessWithPoint.h"
#include "ProcessWithSpace.h"
#include "MyFactory.h"

#include "gtest/gtest.h"

TEST(ProcessWithWordTest, rearrangeWord) {
  ProcessWithWord pww;
	
  EXPECT_EQ(pww.process("123 456 789", 11), "789 456 123");
  EXPECT_EQ(pww.process("abc def ghi", 11), "ghi def abc");
  
  EXPECT_EQ(pww.process("  123  456  789", 15), "789 456 123");
  EXPECT_EQ(pww.process("  abc def    ghi", 16), "ghi def abc");
  
  EXPECT_EQ(pww.process("  123   456 789   ", 18), "789 456 123");
  EXPECT_EQ(pww.process("  abc  def ghi  ", 16), "ghi def abc");
  
  EXPECT_EQ(pww.process("--*/123__ 456..789", 18), "789 456 123");
  EXPECT_EQ(pww.process("/_=abc  def!!ghi", 16), "ghi def abc");
  
  EXPECT_EQ(pww.process("*-/_+!@#%$////.....", 19), "");
  EXPECT_EQ(pww.process("abcdefghi", 9), "abcdefghi");

  EXPECT_NE(pww.process("  123   456 789   ", 18), "123 456 789");
  EXPECT_NE(pww.process("  abc  def ghi  ", 16), "abc def ghi");
}

TEST(ProcessWithPointTest, replaceComma){
  ProcessWithPoint pwp;
	
  EXPECT_EQ(pwp.process(",,123, 456,, ,789,", 18), "..123. 456.. .789.");
  EXPECT_EQ(pwp.process(",abc,,,, ,def, ghi,", 19), ".abc.... .def. ghi.");

  EXPECT_NE(pwp.process(",,123, 456,, ,789,", 18), "..123, 456.. .789.");
  EXPECT_NE(pwp.process(",abc,,,, ,def, ghi,", 19), ".abc.,.. .def. ghi.");
}

TEST(ProcessWithSpaceTest, deleteSpace){
  ProcessWithSpace pws;
  EXPECT_EQ(pws.process("123 456 789", 11), "123456789");
  EXPECT_EQ(pws.process("abc def ghi", 11), "abcdefghi");

  EXPECT_EQ(pws.process("   123 456   789   ", 19 ), "123456789");
  EXPECT_EQ(pws.process("  abc def    ghi  ", 18 ), "abcdefghi");

  EXPECT_NE(pws.process("   123 456   789   ", 19 ), "1234 56789");
  EXPECT_NE(pws.process("  abc def    ghi  ", 18 ), "abcdef ghi");
}

TEST(MyFactoryTest, createObject){
  MyFactory mf;
  ProcessWithWord pww;
  ProcessWithPoint pwp;
  ProcessWithSpace pws;

  EXPECT_EQ(mf.createProcessor('a'), nullptr);

  EXPECT_EQ(typeid(*mf.createProcessor('A')), typeid(pww));
  EXPECT_EQ(typeid(*mf.createProcessor('B')), typeid(pwp));
  EXPECT_EQ(typeid(*mf.createProcessor('C')), typeid(pws));

  EXPECT_NE(typeid(*mf.createProcessor('A')), typeid(pws));
}

