using System;
using System.Windows.Forms;

namespace UserLoginApp
{
    public partial class PersonalForm : Form
    {
#pragma warning disable CS8618 // Un campo que no acepta valores NULL debe contener un valor distinto de NULL al salir del constructor. Considere la posibilidad de declararlo como que admite un valor NULL.
        public PersonalForm()
#pragma warning restore CS8618 // Un campo que no acepta valores NULL debe contener un valor distinto de NULL al salir del constructor. Considere la posibilidad de declararlo como que admite un valor NULL.
        {
            InitializeComponent();
            InitializeHabitaciones();
        }

        private class Habitacion
        {
            public string Nombre { get; }
            public int CapacidadMaxima { get; }
            public float CostoPorNoche { get; }

            public Habitacion(string nombre, int capacidadMaxima, float costoPorNoche)
            {
                Nombre = nombre;
                CapacidadMaxima = capacidadMaxima;
                CostoPorNoche = costoPorNoche;
            }

            public float CalcularCostoTotal(int numDias, bool esAdultoMayor, bool esNino, float descuentoAdultoMayor, float descuentoNino)
            {
                float costoTotal = CostoPorNoche * numDias;

                if (esAdultoMayor)
                {
                    costoTotal *= (1 - descuentoAdultoMayor);
                }
                else if (esNino)
                {
                    costoTotal *= (1 - descuentoNino);
                }

                return costoTotal;
            }

            public override string ToString()
            {
                return Nombre;
            }
        }

        private Habitacion[] habitaciones;

        private void InitializeHabitaciones()
        {
            habitaciones = new Habitacion[]
            {
                new Habitacion("Habitación Normal", 3, 3000),
                new Habitacion("Suite", 6, 8000),
                new Habitacion("Habitación Imperial", 10, 12000),
                new Habitacion("Villa", 15, 20000)
            };

            cmbTipoHabitacion.Items.AddRange(habitaciones);
        }

        private void btnReservar_Click(object sender, EventArgs e)
        {
            string nombreCliente = txtNombre.Text;

            if (!int.TryParse(txtEdad.Text, out int edadCliente) || !int.TryParse(txtNumAdultos.Text, out int numAdultos) ||
                !int.TryParse(txtNumNinos.Text, out int numNinos) || !int.TryParse(txtNumDias.Text, out int numDias) ||
                cmbTipoHabitacion.SelectedItem == null)
            {
                MessageBox.Show("Por favor, ingrese todos los datos correctamente.");
                return;
            }

            Habitacion tipoHabitacion = (Habitacion)cmbTipoHabitacion.SelectedItem;
            bool esAdultoMayor = edadCliente > 60;
            bool esNino = edadCliente < 10;

            float descuentoAdultoMayor = esAdultoMayor ? 0.3f : 0.0f;
            float descuentoNino = esNino ? 0.15f : 0.0f;

            float costoTotal = tipoHabitacion.CalcularCostoTotal(numDias, esAdultoMayor, esNino, descuentoAdultoMayor, descuentoNino);

            FormCostoTotal costoTotalForm = new FormCostoTotal(costoTotal);
            costoTotalForm.ShowDialog();
        }

        private void label1_Click(object sender, EventArgs e) { }
        private void label5_Click(object sender, EventArgs e) { }
        private void pictureBox5_Click(object sender, EventArgs e) { }
        private void Form1_Load(object sender, EventArgs e) { }
        private void pictureBox1_Click(object sender, EventArgs e) { }

        private void pictureBox4_Click(object sender, EventArgs e)
        {

        }
    }
}
