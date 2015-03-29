/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_PRINTF_ELEM_H
# define TWL_PRINTF_ELEM_H

# define MAX_VA_LIST_ELEM 8

# define CONV_SPEC_ALL "sdpSDioOuUxXcCfF"
# define CONV_SPEC_S 's'
# define CONV_SPEC_D 'd'
# define CONV_SPEC_P 'p'
# define CONV_SPEC_S_UP 'S'
# define CONV_SPEC_D_UP 'D'
# define CONV_SPEC_I 'i'
# define CONV_SPEC_O 'o'
# define CONV_SPEC_O_UP 'O'
# define CONV_SPEC_U 'u'
# define CONV_SPEC_U_UP 'U'
# define CONV_SPEC_X 'x'
# define CONV_SPEC_X_UP 'X'
# define CONV_SPEC_C 'c'
# define CONV_SPEC_C_UP 'C'
# define CONV_SPEC_F 'f'
# define CONV_SPEC_F_UP 'F'
# define CONV_SPEC_LD ('l' * 1000) + 'd'
# define CONV_SPEC_LI ('l' * 1000) + 'i'
# define CONV_SPEC_LU ('l' * 1000) + 'u'
# define CONV_SPEC_LO ('l' * 1000) + 'o'
# define CONV_SPEC_LX ('l' * 1000) + 'x'
# define CONV_SPEC_LX_UP ('l' * 1000) + 'X'
# define CONV_SPEC_LC ('l' * 1000) + 'c'
# define CONV_SPEC_LS ('l' * 1000) + 's'
# define CONV_SPEC_LLD ('l' * 'l' * 1000) + 'd'
# define CONV_SPEC_LLI ('l' * 'l' * 1000) + 'i'
# define CONV_SPEC_LLU ('l' * 'l' * 1000) + 'u'
# define CONV_SPEC_LLO ('l' * 'l' * 1000) + 'o'
# define CONV_SPEC_LLX ('l' * 'l' * 1000) + 'x'
# define CONV_SPEC_LLX_UP ('l' * 'l' * 1000) + 'X'
# define CONV_SPEC_HD ('h'  * 1000) + 'd'
# define CONV_SPEC_HI ('h'  * 1000) + 'i'
# define CONV_SPEC_HU ('h'  * 1000) + 'u'
# define CONV_SPEC_HO ('h'  * 1000) + 'o'
# define CONV_SPEC_HX ('h'  * 1000) + 'x'
# define CONV_SPEC_HX_UP ('h'  * 1000) + 'X'
# define CONV_SPEC_HHD ('h' * 'h' * 1000) + 'd'
# define CONV_SPEC_HHI ('h' * 'h' * 1000) + 'i'
# define CONV_SPEC_HHU ('h' * 'h' * 1000) + 'u'
# define CONV_SPEC_HHO ('h' * 'h' * 1000) + 'o'
# define CONV_SPEC_HHX ('h' * 'h' * 1000) + 'x'
# define CONV_SPEC_HHX_UP ('h' * 'h' * 1000) + 'X'
# define CONV_SPEC_PERCENT '%'

# define LST_CONV_S "s"
# define LST_CONV_D "d"
# define LST_CONV_P "p"
# define LST_CONV_S_UP "S"
# define LST_CONV_D_UP "D"
# define LST_CONV_I "i"
# define LST_CONV_O "o"
# define LST_CONV_O_UP "O"
# define LST_CONV_U "u"
# define LST_CONV_U_UP "U"
# define LST_CONV_X "x"
# define LST_CONV_X_UP "X"
# define LST_CONV_C "c"
# define LST_CONV_C_UP "C"
# define LST_CONV_F "f"
# define LST_CONV_F_UP "F"
# define LST_CONV_LD "ld"
# define LST_CONV_LI "li"
# define LST_CONV_LU "lu"
# define LST_CONV_LO "lo"
# define LST_CONV_LX "lx"
# define LST_CONV_LX_UP "lX"
# define LST_CONV_LC "lc"
# define LST_CONV_LS "ls"
# define LST_CONV_LLD "lld"
# define LST_CONV_LLI "lli"
# define LST_CONV_LLU "llu"
# define LST_CONV_LLO "llo"
# define LST_CONV_LLX "llx"
# define LST_CONV_LLX_UP "llX"
# define LST_CONV_HD "hd"
# define LST_CONV_HI "hi"
# define LST_CONV_HU "hu"
# define LST_CONV_HO "ho"
# define LST_CONV_HX "hx"
# define LST_CONV_HX_UP "hX"
# define LST_CONV_HHD "hhd"
# define LST_CONV_HHI "hhi"
# define LST_CONV_HHU "hhu"
# define LST_CONV_HHO "hho"
# define LST_CONV_HHX "hhx"
# define LST_CONV_HHX_UP "hhX"
# define LST_CONV_PERCENT "%"

# define SEG_FLAG 0
# define SEG_MIN_WIDTH 1
# define SEG_PRECISION 2
# define SEG_LENGTH_MODIF 3
# define SEG_CONV_SPEC 4
# define SEG_COUNT 5

# define DIGIT_ALL "0123456789"
# define PRECISION_ALL ".*"DIGIT_ALL
# define PRECISION_NOT_SET -1
# define PRECISION_WILDCARD_VAL -2

# define LEN_MOD_ALL "lhjz"
# define MIN_WIDTH_ALL "*"DIGIT_ALL
# define MIN_WIDTH_WILDCARD_VAL -1

# define FLAGS_ALL "#-0+ "
# define FLAG_SHARP '#'
# define FLAG_SHARP_MASK 1
# define FLAG_MINUS '-'
# define FLAG_MINUS_MASK 2
# define FLAG_ZERO '0'
# define FLAG_ZERO_MASK 4
# define FLAG_PLUS '+'
# define FLAG_PLUS_MASK 8
# define FLAG_SPACE ' '
# define FLAG_SPACE_MASK 16

# define FULL_CONV_SPEC(length_mod, conv_spec) ((length_mod * 1000) + conv_spec)

# define STRING_OF_NULL "(null)"
# define REPLACEMENT_FOR_NULL_CHAR 'Z'

# define VALID_CHARS_BEFORE_CONV_SPEC ".*"FLAGS_ALL""LEN_MOD_ALL""DIGIT_ALL

# define PREFIX_FOR_POINTER "0x"

typedef struct		s_pf_elem
{
	int		conv_spec;
	char	*conv_spec_str;
	int		flags;
	int		min_width;
	int		precision;
	int		length_modifier;
	char	*length_modifier_str;
	int		c_is_null_char;
	void	**values;
	int		values_count;
	char	**split;
	char	*raw;
	char	*str;
	char	*prefix;
	char	*(*conv_to_str)(void *);
}					t_pfelem;

t_pfelem			*pfelem_create(char *s);
void				*pfelem_str2pfelem(void *data);
void				pfelem_split(t_pfelem *pfelem);
int					pfelem_is_raw_string(t_pfelem *pfelem);
void				pfelem_convert_to_str(t_pfelem *pfelem);
void				pfelem_split(t_pfelem *pfelem);
void				pfelem_split_process(t_pfelem *pfelem);
void				pfelem_split_build(t_pfelem *pfelem);
void				pfelem_flag_add(t_pfelem *pfelem);
void				pfelem_min_width_add(t_pfelem *pfelem);
void				pfelem_precision_add(t_pfelem *pfelem);
void				pfelem_pre_str_conv(t_pfelem *pfelem);
void				pfelem_post_str_conv(t_pfelem *pfelem);
int					pfelem_has_valid_conv_spec(t_pfelem *pfelem);
int					pfelem_fill_before_padding(t_pfelem *pfelem);
void				pfelem_free(t_pfelem *elem);

void				pfelem_set_conv_spec(t_pfelem *pfelem, char *conv_spec);
void				pfelem_set_length_modifier(t_pfelem *pfelem, char *len_mod);
void				pfelem_set_flags(t_pfelem *pfelem, char *flags);
void				pfelem_set_min_width(t_pfelem *pfelem, char *raw);
int					pfelem_get_value_or_wildcard(char *raw, int default_val,
													int original_val);
void				pfelem_set_precision(t_pfelem *pfelem, char *raw);
void				pfelem_precision_set_wildcard(t_pfelem *pfelem);
void				pfelem_precision_handle_strings(t_pfelem *pfelem);
void				pfelem_precision_handle_digits(t_pfelem *pfelem);

void				pfelem_min_width_pad(t_pfelem *pfelem, int pad_dir,
															char fill_char);
#endif
