#include <gtest/gtest.h>
#include <ApprovalTests/Approvals.h>

using namespace ApprovalTests;

TEST(GoogleTestApprovalsTests, YouCanVerifyText)
{
    Approvals::verify("My objects!");
}

TEST(GoogleTestApprovalsTests, TestStreamableObject)
{
    Approvals::verify(42);
}
