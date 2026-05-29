#!/bin/bash

set -euo pipefail

PROJECT_DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$PROJECT_DIR"

make fclean >/dev/null
make >/dev/null

pass_count=0

assert_output() {
    local input="$1"
    local expected="$2"
    local actual

    actual="$(./convert "$input")"

    if [[ "$actual" != "$expected" ]]; then
        echo "[FAIL] input: $input"
        echo "Expected:"
        printf '%s\n' "$expected"
        echo "Actual:"
        printf '%s\n' "$actual"
        exit 1
    fi

    pass_count=$((pass_count + 1))
}

assert_output "42" $'char: \'*\'\nint: 42\nfloat: 42.0f\ndouble: 42.0'
assert_output "a" $'char: \'a\'\nint: 97\nfloat: 97.0f\ndouble: 97.0'
assert_output "0.0f" $'char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0'
assert_output "nan" $'char: impossible\nint: impossible\nfloat: nanf\ndouble: nan'
assert_output "+inf" $'char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf'
assert_output "+inff" $'char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf'
assert_output "-inf" $'char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf'
assert_output "" $'Error: invalid literal'
expected_plus=$(cat <<'EOF'
char: '+'
int: 43
float: 43.0f
double: 43.0
EOF
)
assert_output "+" "$expected_plus"
expected_dot=$(cat <<'EOF'
char: '.'
int: 46
float: 46.0f
double: 46.0
EOF
)
assert_output "." "$expected_dot"
assert_output ".f" $'Error: invalid literal'

echo "✅ All $pass_count ScalarConverter tests passed."