namespace leccion1cliente
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.grados_tb = new System.Windows.Forms.TextBox();
            this.cel_bt = new System.Windows.Forms.Button();
            this.far_bt = new System.Windows.Forms.Button();
            this.desconectar_bt = new System.Windows.Forms.Button();
            this.conectar_bt = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // grados_tb
            // 
            this.grados_tb.Location = new System.Drawing.Point(317, 122);
            this.grados_tb.Name = "grados_tb";
            this.grados_tb.Size = new System.Drawing.Size(156, 31);
            this.grados_tb.TabIndex = 0;
            // 
            // cel_bt
            // 
            this.cel_bt.Location = new System.Drawing.Point(222, 210);
            this.cel_bt.Name = "cel_bt";
            this.cel_bt.Size = new System.Drawing.Size(114, 66);
            this.cel_bt.TabIndex = 1;
            this.cel_bt.Text = "Convertir a Celsius";
            this.cel_bt.UseVisualStyleBackColor = true;
            this.cel_bt.Click += new System.EventHandler(this.cel_bt_Click);
            // 
            // far_bt
            // 
            this.far_bt.Location = new System.Drawing.Point(430, 210);
            this.far_bt.Name = "far_bt";
            this.far_bt.Size = new System.Drawing.Size(114, 66);
            this.far_bt.TabIndex = 2;
            this.far_bt.Text = "Convertir a ºF";
            this.far_bt.UseVisualStyleBackColor = true;
            this.far_bt.Click += new System.EventHandler(this.far_bt_Click);
            // 
            // desconectar_bt
            // 
            this.desconectar_bt.Location = new System.Drawing.Point(625, 166);
            this.desconectar_bt.Name = "desconectar_bt";
            this.desconectar_bt.Size = new System.Drawing.Size(114, 66);
            this.desconectar_bt.TabIndex = 3;
            this.desconectar_bt.Text = "Desconectar";
            this.desconectar_bt.UseVisualStyleBackColor = true;
            this.desconectar_bt.Click += new System.EventHandler(this.desconectar_bt_Click);
            // 
            // conectar_bt
            // 
            this.conectar_bt.Location = new System.Drawing.Point(625, 61);
            this.conectar_bt.Name = "conectar_bt";
            this.conectar_bt.Size = new System.Drawing.Size(114, 66);
            this.conectar_bt.TabIndex = 4;
            this.conectar_bt.Text = "Conectar";
            this.conectar_bt.UseVisualStyleBackColor = true;
            this.conectar_bt.Click += new System.EventHandler(this.conectar_bt_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.conectar_bt);
            this.Controls.Add(this.desconectar_bt);
            this.Controls.Add(this.far_bt);
            this.Controls.Add(this.cel_bt);
            this.Controls.Add(this.grados_tb);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox grados_tb;
        private System.Windows.Forms.Button cel_bt;
        private System.Windows.Forms.Button far_bt;
        private System.Windows.Forms.Button desconectar_bt;
        private System.Windows.Forms.Button conectar_bt;
    }
}

