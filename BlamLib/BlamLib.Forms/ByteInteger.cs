/*
	BlamLib: .NET SDK for the Blam Engine

	See license\BlamLib\BlamLib for specific license information
*/
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace BlamLib.Forms
{
	public partial class ByteInteger : BlamLib.Forms.Field
	{
		public byte Field
		{
			get { try { return Convert.ToByte(field.Text); } catch { return 0; } }
			set { field.Text = value.ToString(); }
		}

		public ByteInteger()
		{
			InitializeComponent();

			_Setup(name, units);
		}

		public override void Clear() { field.Text = ""; }

		public override void AddEventHandlers(params object[] handlers) { field.TextChanged += (handlers[0] as EventHandler); }
	};
}