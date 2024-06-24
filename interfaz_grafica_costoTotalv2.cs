using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UserLoginApp
{
    public partial class FormCostoTotal : Form
    {
        private float costoTotal;

        public FormCostoTotal(float costoTotal)
        {
            InitializeComponent();
            this.costoTotal = costoTotal;
            lblCostoTotal.Text = $"El costo total de la reserva sería de ${costoTotal}.00 con el descuento aplicado.";


        }



        private void btnCalcularCambio_Click(object sender, EventArgs e)
        {
            float montoPagado;
            if (float.TryParse(txtMontoPagado.Text, out montoPagado))
            {
                if (montoPagado > costoTotal)
                {
                    float cambio = montoPagado - costoTotal;
                    lblCambio.Text = $"Cambio: ${cambio:F2}";
                }
                else
                {
                    MessageBox.Show("El monto pagado es insuficiente para cubrir el costo total.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            else
            {
                MessageBox.Show("Por favor, ingrese un monto válido.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void FormCostoTotal_Load(object sender, EventArgs e)
        {

        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox2_Click_1(object sender, EventArgs e)
        {

        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox5_Click_1(object sender, EventArgs e)
        {

        }

        private void pictureBox6_Click(object sender, EventArgs e)
        {

        }
    }
}
