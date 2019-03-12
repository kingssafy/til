def sum_math_v_vi_average(dict_list):
    result_list = []
    for claim in dict_list:
        result_list.append(dict(claim.items()))
    for a_dict in result_list:
        a_dict['V+VI'] = (a_dict.pop('V') + a_dict.pop('VI'))/2
    return result_list
    
    



student_details= [
  {'id' : 1, 'subject' : 'math', 'V' : 70, 'VI' : 82},
  {'id' : 2, 'subject' : 'math', 'V' : 73, 'VI' : 74},
  {'id' : 3, 'subject' : 'math', 'V' : 75, 'VI' : 86}
]
print(sum_math_v_vi_average(student_details))
