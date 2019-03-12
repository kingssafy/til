import unittest
from survey import AnonymousSurvey

class test_AnonymousSurvey(unittest.TestCase):
    """test for the class AnonymousSurvey"""

    def setUp(self):
        """
        Create a survey and a set of responses for use in all test method.
        """
        question = "What language did you first learn to speak?"
        self.my_survey = AnonymousSurvey(question)
        self.responses = ['English', 'Spanish', 'Mandrain']
    def test_store_single_response(self):
        """Test that a sngle response is sotred properly."""
        question = "What language did you first learn to speak?"
        self.my_survey.store_response(self.responses[0])
        self.assertIn(self.responses[0], self.my_survey.responses)

    def test_store_three_responses(self):
        """Test that three individual responses are stored properly."""
        question = "What language did you first laern to sepak?"
        for response in self.responses:
            self.my_survey.store_response(response)

        for response in self.responses:
            self.assertIn(response, self.my_survey.responses)

unittest.main()
