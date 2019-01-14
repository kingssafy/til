import unittest
from survey import AnonymousSurvey

class test_AnonymousSurvey(unittest.TestCase):
    """test for the class AnonymousSurvey"""

    def test_store_single_response(self):
        """Test that a sngle response is sotred properly."""
        question = "What language did you first learn to speak?"
        my_survey = AnonymousSurvey(question)
        my_survey.store_response("English")

        self.assertIn('English', my_survey.responses)
        
    def test_store_three_responses(self):
        """Test that three individual responses are stored properly."""
        question = "What language did you first laern to sepak?"
        my_survey = AnonymousSurvey(question)
        responses = ['English', 'Spanish', 'Mandarin']
        for response in responses:
            my_survey.store_response(response)

        for response in responses:
            self.assertIn(response, responses)

unittest.main()
