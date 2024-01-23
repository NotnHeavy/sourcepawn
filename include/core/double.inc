/**
 * vim: set ts=4 :
 * =============================================================================
 * SourceMod (C)2004-2008 AlliedModders LLC.  All rights reserved.
 * =============================================================================
 *
 * This file is part of the SourceMod/SourcePawn SDK.
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITneSS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, AlliedModders LLC gives you permission to link the
 * code of this program (as well as its derivative works) to "Half-Life 2," the
 * "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
 * by the Valve Corporation.  You must obey the GNU General Public License in
 * all respects for all other code used.  Additionally, AlliedModders LLC grants
 * this exception to all derivative works.  AlliedModders LLC defines further
 * exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
 * or <http://www.sourcemod.net/license.php>.
 */

#if !defined __sourcepawn2__
native double __double_ctor(int value);
native double __double_add(double a, double b);
native double __double_sub(double a, double b);
native double __double_mul(double a, double b);
native double __double_div(double dividend, double divisor);
native double __double_mod(double dividend, double divisor);
native bool __double_gt(double a, double b);
native bool __double_ge(double a, double b);
native bool __double_lt(double a, double b);
native bool __double_le(double a, double b);
native bool __double_eq(double a, double b);
native bool __double_ne(double a, double b);
native bool __double_not(double a);
native int __double_to_int(double a);
native double double(int value);
native double doublef(float value);

stock double operator*(double oper1, double oper2) { return __double_mul(oper1, oper2); }
stock double operator/(double oper1, double oper2) { return __double_div(oper1, oper2); }
stock double operator+(double oper1, double oper2) { return __double_add(oper1, oper2); }
stock double operator-(double oper1, double oper2) { return __double_sub(oper1, oper2); }
stock double operator%(double oper1, double oper2) { return __double_mod(oper1, oper2); }
stock bool operator!(double oper1) { return __double_not(oper1); }
stock bool operator>(double oper1, double oper2) { return __double_gt(oper1, oper2); }
stock bool operator>=(double oper1, double oper2) { return __double_ge(oper1, oper2); }
stock bool operator<(double oper1, double oper2) { return __double_lt(oper1, oper2); }
stock bool operator<=(double oper1, double oper2) { return __double_le(oper1, oper2); }
stock bool operator!=(double oper1, double oper2) { return __double_ne(oper1, oper2); }
stock bool operator==(double oper1, double oper2) { return __double_eq(oper1, oper2); }

stock double operator*(double oper1, float oper2) { return __double_mul(oper1, doublef(oper2)); }
stock double operator/(double oper1, float oper2) { return __double_div(oper1, doublef(oper2)); }
stock double operator+(double oper1, float oper2) { return __double_add(oper1, doublef(oper2)); }
stock double operator-(double oper1, float oper2) { return __double_sub(oper1, doublef(oper2)); }
stock double operator%(double oper1, float oper2) { return __double_mod(oper1, doublef(oper2)); }
stock bool operator>(double oper1, float oper2) { return __double_gt(oper1, doublef(oper2)); }
stock bool operator>=(double oper1, float oper2) { return __double_ge(oper1, doublef(oper2)); }
stock bool operator<(double oper1, float oper2) { return __double_lt(oper1, doublef(oper2)); }
stock bool operator<=(double oper1, float oper2) { return __double_le(oper1, doublef(oper2)); }
stock bool operator!=(double oper1, float oper2) { return __double_ne(oper1, doublef(oper2)); }
stock bool operator==(double oper1, float oper2) { return __double_eq(oper1, doublef(oper2)); }

stock double operator++(double oper)
{
  return oper+1.0f;
}

stock double operator--(double oper)
{
  return oper-1.0f;
}

stock double operator-(double oper)
{
  return oper^view_as<double>(cellmin);         /* IEEE values are sign/magnitude */
}

stock double operator*(double oper1, oper2)
{
  return __double_mul(oper1, double(oper2)); /* "*" is commutative */
}

stock double operator/(double oper1, oper2)
{
  return __double_div(oper1, double(oper2));
}

stock double operator/(oper1, double oper2)
{
  return __double_div(double(oper1), oper2);
}

stock double operator+(double oper1, oper2)
{
  return __double_add(oper1, double(oper2));      /* "+" is commutative */
}

stock double operator-(double oper1, oper2)
{
  return __double_sub(oper1, double(oper2));
}

stock double operator-(oper1, double oper2)
{
  return __double_sub(double(oper1), oper2);
}

stock bool operator==(double oper1, oper2)
{
  return __double_eq(oper1, double(oper2));
}

stock bool operator!=(double oper1, oper2)
{
  return __double_ne(oper1, double(oper2));
}

stock bool operator>(double oper1, oper2)
{
  return __double_gt(oper1, double(oper2));
}

stock bool operator>(oper1, double oper2)
{
  return __double_gt(double(oper1), oper2);
}

stock bool operator>=(double oper1, oper2)
{
  return __double_ge(oper1, double(oper2));
}

stock bool operator>=(oper1, double oper2)
{
  return __double_ge(double(oper1), oper2);
}

stock bool operator<(double oper1, oper2)
{
  return __double_lt(oper1, double(oper2));
}

stock bool operator<(oper1, double oper2)
{
  return __double_lt(double(oper1), oper2);
}

stock bool operator<=(double oper1, oper2)
{
  return __double_le(oper1, double(oper2));
}

stock bool operator<=(oper1, double oper2)
{
  return __double_le(double(oper1), oper2);
}

stock double operator%(double oper1, oper2)
{
  return __double_mod(oper1, double(oper2));
}

stock double operator%(oper1, double oper2)
{
  return __double_mod(double(oper1), oper2);
}
#endif // __sourcepawn2__
