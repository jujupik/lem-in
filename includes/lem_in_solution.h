/* ************************************************************************** 
/*                                                                            
/*                                                        :::      ::::::::   
/*   lem_in.h                                           :+:      :+:    :+:   
/*                                                    +:+ +:+         +:+     
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        
/*                                                +#+#+#+#+#+   +#+           
/*   Created: 2020/01/29 13:43:55 by jrouchon          #+#    #+#             
/*   Updated: 2020/01/29 13:43:57 by jrouchon         ###   ########.fr       
/*                                                                            
/* ************************************************************************** 

#ifndef LEM_IN_SOLUTION_H
# define LEM_IN_SOLUTION_H

typedef struct		s_solution
{
	t_path_list		paths;
	float			note;
}					t_solution;

t_solution			create_solution();
void				destroy_solution(t_solution to_destroy);
void				add_path_to_solution(t_solution *solution, t_path to_add);
void				clear_solution(t_solution *solution);
void				print_solution(t_solution *solution);
void				calc_solution_note(t_solution *solution);
void				copy_solution(t_solution *dest, t_solution *src);
void				reverse_solution(t_solution *solution);

#endif
