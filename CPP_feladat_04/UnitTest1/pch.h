// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#define ARE_EQUAL(expVal, actVal) Assert::AreEqual(expVal, actVal, L"-", LINE_INFO())
#define ARE_EQUALSTR(expVal, actVal) Assert::AreEqual((const char *)expVal, (const char *)actVal, L"-", LINE_INFO())
#define ARE_EQUALPTR(expVal, actVal) Assert::AreEqual((char *)expVal, (char *)actVal, L"-", LINE_INFO())

#define ARE_NOTEQUAL(expVal, actVal) Assert::AreNotEqual(expVal, actVal, L"-", LINE_INFO())
#define ARE_NOTEQUALSTR(expVal, actVal) Assert::AreNotEqual((const char *)expVal, (const char *)actVal, L"-", LINE_INFO())
#define ARE_NOTEQUALPTR(expVal, actVal) Assert::AreNotEqual((char *)expVal, (char *)actVal, L"-", LINE_INFO())

#define IS_TRUE(b) Assert::IsTrue(b, L"-", LINE_INFO())
#define WRITE(s) Logger::WriteMessage((const char*)s)
#define TEST(expVal, actVal, msg) Assert::AreEqual(expVal, actVal, msg, LINE_INFO())

#endif //PCH_H
