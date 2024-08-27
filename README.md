# VOTING-SYSTEM-USING-C
Voting System
Overview
This Mini Voting System is a command-line application implemented in C that allows users to manage a list of candidates, cast votes, and determine the winner based on the highest vote count. The system supports adding candidates, voting for them, deleting candidates, and displaying the winner.

Features
Add Candidate: Add a new candidate with a name and a unique number.
Display Candidates: List all candidates along with their unique numbers.
Cast Vote: Vote for a candidate by specifying their unique number.
Delete Candidate: Remove a candidate from the list using their unique number.
Display Winner: Display the candidate with the highest vote count and exit the program.

How It Works
Candidate Management: Candidates are stored in a singly linked list, which allows for dynamic addition and deletion.
Voting System: Users can cast votes for candidates, which increments their vote count.
Winner Determination: At the end of voting, the system determines and displays the candidate with the most votes.
