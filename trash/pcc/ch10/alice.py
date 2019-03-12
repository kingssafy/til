def count_words(filename):
    """Count the approximate number of words in a file."""
    try:
        with open(filename) as f_obj:
            contents = f_obj.read()
    except FileNotFoundError:
        message = "Sorry, the file " + filename + " does not exist."
        print(message)
    else:
        words = contents.split()
        num_words = len(words)
        ("The file " + filename+ " has about "+ str(num_words) + "words.")

filename = 'alice.txt'
count_words(filename)
