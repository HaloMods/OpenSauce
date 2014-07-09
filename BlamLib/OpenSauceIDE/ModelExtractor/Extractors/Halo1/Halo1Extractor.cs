﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using BlamLib.IO;
using BlamLib.Managers;
using BlamLib.TagInterface;
using OpenSauceIDE.ModelExtractor.MessageHandler;
using OpenSauceIDE.ModelExtractor.TagIO;
using H1 = BlamLib.Blam.Halo1;

namespace OpenSauceIDE.ModelExtractor.Extractors.Halo1
{
    /// <summary>   A halo 1 extractor job base class. </summary>
    public abstract class Halo1ExtractorJob
        : IMessageSource
    {
        #region Messaging
        protected IMessageHandler mMessageHandler = new MessageHandler.MessageHandler();

        /// <summary>   Event queue for all listeners interested in MessageSent events. </summary>
        public event EventHandler<ModelExtractorMessageArgs> MessageSent
        {
            add { mMessageHandler.MessageSent += value; }
            remove { mMessageHandler.MessageSent -= value; }
        }
        
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// <summary>   Passes a message through to the message handler. </summary>
        ///
        /// <param name="sender">   Source of the event. </param>
        /// <param name="e">        The ModelExtractorMessageArgs to process. </param>
        protected void MessageRedirect(object sender, ModelExtractorMessageArgs e)
        {
            mMessageHandler.SendMessage(e.Message);
        }

        void IndexInterfaceErrorOccurred(object sender, TagIndex.TagIndexErrorArgs e)
        {
            mMessageHandler.SendMessage(e.Message);
        }
        #endregion

        private BlamLib.TagInterface.TagGroup[] kIgnoredTagGroups =
		{
			H1.TagGroups.actr, H1.TagGroups.actv, H1.TagGroups.ant_, H1.TagGroups.antr,
			H1.TagGroups.bipd, H1.TagGroups.boom, H1.TagGroups.cdmg, H1.TagGroups.coll,
			H1.TagGroups.colo, H1.TagGroups.cont, H1.TagGroups.deca, H1.TagGroups.DeLa,
			H1.TagGroups.devc, H1.TagGroups.dobc, H1.TagGroups.effe, H1.TagGroups.elec,
			H1.TagGroups.eqip, H1.TagGroups.flag, H1.TagGroups.fog_, H1.TagGroups.font,
			H1.TagGroups.foot, H1.TagGroups.garb, H1.TagGroups.gelo, H1.TagGroups.glw_,
			H1.TagGroups.grhi, H1.TagGroups.hmt_, H1.TagGroups.hud_, H1.TagGroups.hudg,
			H1.TagGroups.item, H1.TagGroups.itmc, H1.TagGroups.jpt_, H1.TagGroups.lens,
			H1.TagGroups.lsnd, H1.TagGroups.matg, H1.TagGroups.metr, H1.TagGroups.mgs2,
			H1.TagGroups.mply, H1.TagGroups.ngpr, H1.TagGroups.part, H1.TagGroups.pctl,
			H1.TagGroups.phys, H1.TagGroups.plac, H1.TagGroups.pphy,
			H1.TagGroups.proj, H1.TagGroups.rain, H1.TagGroups.seff, H1.TagGroups.sky_,
			H1.TagGroups.snd_, H1.TagGroups.snde, H1.TagGroups.Soul, H1.TagGroups.str_,
			H1.TagGroups.tag_, H1.TagGroups.tagc, H1.TagGroups.trak, H1.TagGroups.udlg,
			H1.TagGroups.unhi, H1.TagGroups.unit, H1.TagGroups.ustr, H1.TagGroups.vcky,
			H1.TagGroups.vehi, H1.TagGroups.weap, H1.TagGroups.wind, H1.TagGroups.wphi,
			H1.TagGroups.yelo
		};

        private ExtractorTagIndexHandler<BlamLib.Managers.TagIndex> mTagIndexHandler;

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// <summary>   Gets the tag index. </summary>
        ///
        /// <value> The tag index. </value>
        protected TagIndexBase TagIndex
        {
            get
            {
                if (mTagIndexHandler == null)
                {
                    return null;
                }

                return mTagIndexHandler.IndexInterface;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// <summary>   Creates a Halo 1 tag index. </summary>
        ///
        /// <param name="rootDirectory">    Pathname of the root directory. </param>
        /// <param name="tagsFolder">       Pathname of the tags folder. </param>
        ///
        /// <returns>   true if it succeeds, false if it fails. </returns>
        protected bool CreateTagIndex(string rootDirectory, string tagsFolder)
        {
            mTagIndexHandler = new ExtractorTagIndexHandler<BlamLib.Managers.TagIndex>(BlamLib.BlamVersion.Halo1_CE, rootDirectory, tagsFolder);

            if(mTagIndexHandler == null)
            {
                return false;
            }

            mTagIndexHandler.IndexInterface.SetupIgnoreList(kIgnoredTagGroups);
            mTagIndexHandler.IndexInterface.ErrorOccurred +=IndexInterfaceErrorOccurred;

            return true;
        }

        /// <summary>   Destroys the tag index. </summary>
        protected void DestroyTagIndex()
        {
            if (mTagIndexHandler != null)
            {
                mTagIndexHandler.IndexInterface.ErrorOccurred -= IndexInterfaceErrorOccurred;
                mTagIndexHandler.IndexInterface.UnloadAll();
                mTagIndexHandler.Dispose();
                mTagIndexHandler = null;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// <summary>   Opens a tag. </summary>
        ///
        /// <param name="tagPath">  Full pathname of the tag file. </param>
        /// <param name="tagGroup"> Group the tag belongs to. </param>
        ///
        /// <returns>   A BlamLib.Managers.TagManager. </returns>
        protected BlamLib.Managers.TagManager OpenTag(string tagPath, TagGroup tagGroup)
        {
            var datumIndex = mTagIndexHandler.IndexInterface.Open(tagPath, tagGroup, ITagStreamFlags.LoadDependents);

            if(!datumIndex.IsValid)
            {
                return null;
            }

            var tagManager = mTagIndexHandler.IndexInterface[datumIndex];

            return tagManager;
        }
    }
}
