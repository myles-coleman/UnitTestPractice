/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Tests for count_leading_characters function

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZ");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, mixed_case_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Zz");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, special_characters_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("!@#$");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, spaces_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("   Z");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

// Tests for has_mixed_case function

TEST(PasswordTest, both_cases)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Zz");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, only_upper_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ZZ");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, only_lower_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("zz");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, no_letters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("!@#$");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, empty_string)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, spaces)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("   Zz");
	ASSERT_EQ(true, actual);
}

// Tests for set/authenticate functions

TEST(PasswordTest, set_password)
{
	Password my_password;
	my_password.set("Zz123456");
	bool actual = my_password.authenticate("Zz123456");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, set_password_fail)
{
	Password my_password;
	my_password.set("Zz123456");
	bool actual = my_password.authenticate("Zz1234567");
	ASSERT_EQ(false, actual);
}

//if the password has already been used
TEST(PasswordTest, set_password_used)
{
	Password my_password;
	my_password.set("Zz123456");
	my_password.set("Zz123456");
	bool actual = my_password.authenticate("Zz123456");
	ASSERT_EQ(false, actual);
}

//if pass_history is empty
TEST(PasswordTest, pass_history_empty_set)
{
	Password my_password;
	bool actual = my_password.authenticate("Zz123456");
	ASSERT_EQ(false, actual);
}
