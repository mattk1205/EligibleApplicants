# EligibleApplicants
Recursive algorithm to find eligible candidates based on criteria.

Your company wants to hire a new head of PR, and you are tasked with screening off initial applicants. You have decided to using two
criteria to screen the applicants. For each applicant, you measure two quantities:

   • Words per minute (WPM): How many words can the applicant speak per minute and remain clear. You would like that value to be as high as possible.

   • Improper words per minute (IPM): There are certain words/phrases that are deemed improper by your company. You want to detect how likely the applicant would mention those terms. You want that value to be as low as possible.

<em>We consider an applicant x to be an eligible candidate if there is no other applicants that is strictly
better than applicant x in both WPM and IPM. Your task is that, given a pool of applicants, select all the
eligible candidates.<em>

The simplest way of solving this problem is a naïve double for loop.
This algorithm will take O(n^2) time for a set of n applicants. However, there is a recursive solution to this problem that you can implement and can run in O(n log n) time.

# Currently this code runs slower than the iterative approach and stops outputting all eligble candidates after 6569 candidates.
