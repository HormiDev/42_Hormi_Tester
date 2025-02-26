# Definir la variable TESTER_DIR usando el directorio absoluto
TESTER_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

# Definir alias
alias hormi="${TESTER_DIR}/Hormi_Tester.sh"
alias hormi_tester="${TESTER_DIR}/Hormi_Tester.sh"