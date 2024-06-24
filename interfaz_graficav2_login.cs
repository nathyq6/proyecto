using System;
using System.Windows.Forms;
using WinFormsApp13;

namespace UserLoginApp
{
    public partial class Form1 : Form
    {
        // Contraseñas de ejemplo (en una aplicación real, nunca hardcodees contraseñas)
        private const string adminPassword = "123";
        private const string personalPassword = "1234";

        public Form1()
        {
            InitializeComponent();
        }

        private void btnIngresar_Click(object sender, EventArgs e)
        {
            string selectedUserType = cmbUserType.SelectedItem?.ToString();
            string enteredPassword = txtPassword.Text;

            if (selectedUserType == null)
            {
                lblMessage.Text = "Por favor, selecciona un tipo de usuario.";
                lblMessage.ForeColor = System.Drawing.Color.Red;
                return;
            }

            if (enteredPassword == "")
            {
                lblMessage.Text = "Por favor, ingresa una contraseña.";
                lblMessage.ForeColor = System.Drawing.Color.Red;
                return;
            }

            if ((selectedUserType == "Administrador" && enteredPassword == adminPassword) ||
                (selectedUserType == "Personal" && enteredPassword == personalPassword))
            {
                

                if (selectedUserType == "Administrador")
                {
                    AdminForm adminForm = new AdminForm();
                    adminForm.Show();
                }
                else if (selectedUserType == "Personal")
                {
                    PersonalForm personalForm = new PersonalForm();
                    personalForm.Show();
                }
            }
           
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
